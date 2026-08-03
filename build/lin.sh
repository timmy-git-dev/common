set -e

echo "Setting constants..."

TARGET="$1"

# Set project directories.
PATH_PWD="$PWD"
PATH_SRC="$PATH_PWD/src"
PATH_TST="$PATH_PWD/test"
PATH_INC="$PATH_PWD/inc"
PATH_BIN="$PATH_PWD/bin"
PATH_OBJ="$PATH_BIN/obj"
PATH_EXE="$PATH_BIN/common.exe"

# Set compile types.
COMPILE_VERSION="-std=c++23"
FLAGS_BOTH="-g3 -O0 -ffreestanding"
FLAGS_COMP="-fno-exceptions -fno-rtti -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables"
FLAGS_LINK="-nostdlib -nostdinc -static"

# Re-create the object directory.
rm -rf $PATH_OBJ
mkdir -p $PATH_OBJ

echo "Editing .clangd..."

# Create the .clangd file to ensure IDE-syntax works correctly.
cat <<EOF > ${PATH_PWD}/.clangd
CompileFlags:
    Add:
        - -std=c++23
        - --target=$TARGET
        - -I$PATH_INC
        - -Wall
        - -Wextra
        - -Wpedantic
        - -Wunused-value
        - -ffreestanding
        - -fno-exceptions
        - -fno-rtti
        - -fno-stack-protector
        - -fno-asynchronous-unwind-tables
        - -fno-unwind-tables
        - -nostdlib
        - -nostdinc
        - -static
        - -no-pie
EOF

echo "Compiling objects..."

# Gather all .cpp files and compile each one into it's corresponding bin/obj/ location.
PATHS_CPP=$(find "$PATH_SRC" -type f -name "*.cpp")
for PATH_SRC_CPP in $PATHS_CPP; do
    PATH_REL_CPP="${PATH_SRC_CPP#$PATH_SRC}"
    PATH_OBJ_O="$PATH_OBJ${PATH_REL_CPP%.cpp}.o"
    PATH_SUB_OBJ="${PATH_OBJ_O%/*}"

    echo "  Compiling $PATH_REL_CPP..."

    mkdir -p "$PATH_SUB_OBJ"

    clang++ --target=$TARGET $COMPILE_VERSION $FLAGS_BOTH $FLAGS_COMP -I$PATH_INC -c "$PATH_SRC_CPP" -o "$PATH_OBJ_O"
done
PATHS_CPP=$(find "$PATH_TST" -type f -name "*.cpp")
for PATH_TST_CPP in $PATHS_CPP; do
    PATH_REL_CPP="${PATH_TST_CPP#$PATH_TST}"
    PATH_OBJ_O="$PATH_OBJ${PATH_REL_CPP%.cpp}.o"
    PATH_SUB_OBJ="${PATH_OBJ_O%/*}"

    echo "  Compiling $PATH_REL_CPP..."

    mkdir -p "$PATH_SUB_OBJ"

    clang++ --target=$TARGET $COMPILE_VERSION $FLAGS_BOTH $FLAGS_COMP -I$PATH_INC -c "$PATH_TST_CPP" -o "$PATH_OBJ_O"
done

echo "Linking project..."

# Gather all compiled object files and link the project.
PATHS_O=$(find "$PATH_OBJ" -type f -name "*.o")
clang++ --target=$TARGET $COMPILE_VERSION  $FLAGS_BOTH $FLAGS_LINK $PATHS_O -o $PATH_EXE -e start__

set +e
echo "-----"
"$PATH_EXE"
RESULT=$?
echo "-----"

echo "$RESULT"
exit $RESULT