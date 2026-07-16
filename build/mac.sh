#!/usr/bin/env bash

set -e


COMPILER="$1"
TARGET="$2"
OS_FLAGS="$3"

CPP_STANDARD="-std=c++23"
ENTRY="__start"

ROOT="$PWD"
SRC="$ROOT/src"
TST="$ROOT/test"
INC="$ROOT/inc"

BIN="$ROOT/bin"
OBJ="$BIN/obj"
EXE="$BIN/common.exe"


COMMON_FLAGS=(
    "$CPP_STANDARD"
    -g3
    -O0
    -ffreestanding
)

COMPILE_FLAGS=(
    -fno-exceptions
    -fno-rtti
    -fno-stack-protector
    -fno-asynchronous-unwind-tables
    -fno-unwind-tables
)

LINK_FLAGS=(
    -nostdlib
    -static
)

WARNING_FLAGS=(
    -Wall
    -Wextra
    -Wpedantic
    -Wunused-value
)

INCLUDE_FLAGS=(
    "-I$INC"
)


compile_dir() {
    local dir="$1"

    find "$dir" -type f -name "*.cpp" | while read -r cpp; do
        local rel="${cpp#$dir}"
        local obj="$OBJ${rel%.$cpp}.o"

        echo "  Compiling $rel..."

        mkdir -p "$(dirname "$obj")"

        $COMPILER \
            ${OS_FLAGS[@]} \
            ${COMMON_FLAGS[@]} \
            ${COMPILE_FLAGS[@]} \
            ${INCLUDE_FLAGS[@]} \
            -c "$cpp" \
            -o "$obj"
    done
}

link_project() {
    echo "Linking..."

    $COMPILER \
        ${OS_FLAGS[@]} \
        ${COMMON_FLAGS[@]} \
        ${LINK_FLAGS[@]} \
        $(find "$OBJ" -type f -name "*.o") \
        -o "$EXE" \
        -e "$ENTRY"
}

write_clangd() {
    cat > "$ROOT/.clangd" <<EOF
CompileFlags:
    Add:
EOF

    for flag in \
        --target=$TARGET \
        $CPP_STANDARD \
        ${INCLUDE_FLAGS[@]} \
        ${WARNING_FLAGS[@]} \
        ${COMMON_FLAGS[@]} \
        ${COMPILE_FLAGS[@]} \
        ${LINK_FLAGS[@]}
    do
        echo "        - $flag" >> "$ROOT/.clangd"
    done
}


rm -rf "$BIN"
mkdir -p "$OBJ"

write_clangd

echo "Compiling..."
compile_dir "$SRC"
compile_dir "$TST"

link_project


set +e

echo "-----"
$EXE
result=$?
echo "-----"

echo "$result"
exit "$result"