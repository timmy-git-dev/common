# A simple build script to compile the project.

# Set project directories.
PATH_PWD="$PWD"
PATH_SRC="$PATH_PWD/src"
PATH_INC="$PATH_PWD/inc"
PATH_BIN="$PATH_PWD/bin"
PATH_OBJ="$PATH_BIN/obj"
PATH_EXE="$PATH_BIN/common"

# Set compile types.
COMPILE_VERSION="-std=c++23"
COMPILE_FLAGS="-g -O3 -s -ffreestanding -fno-exceptions -fno-rtti -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -nostdlib -nostartfiles -nodefaultlibs -static -no-pie"
COMPILE_LIBRARIES=""

# Re-create the object directory.
rm -rf $PATH_OBJ
mkdir -p $PATH_OBJ

# Create the .clangd file to ensure IDE-syntax works correctly.
cat <<EOF > ${PATH_PWD}/.clangd
CompileFlags:
    Add:
        - -std=c++23
        - -I/home/timmy/code/common/inc
        - -Wall
        - -Wextra
        - -Wpedantic
        - -ffreestanding
        - -fno-exceptions
        - -fno-rtti
        - -fno-stack-protector
        - -fno-asynchronous-unwind-tables
        - -fno-unwind-tables
        - -nostdlib
        - -nostartfiles
        - -nodefaultlibs
        - -static
        - -no-pie

Documentation:
  CommentFormat: Doxygen
EOF

# Gather all .cpp files and compile each one into it's corresponding bin/obj/ location.
PATHS_CPP=$(find "$PATH_SRC" -type f -name "*.cpp")
for PATH_SRC_CPP in $PATHS_CPP; do
    PATH_REL_CPP="${PATH_SRC_CPP#$PATH_SRC}"
    PATH_OBJ_O="$PATH_OBJ${PATH_REL_CPP%.cpp}.o"
    PATH_SUB_OBJ="${PATH_OBJ_O%/*}"

    mkdir -p "$PATH_SUB_OBJ"

    g++ $COMPILE_VERSION $COMPILE_FLAGS $COMPILE_LIBRARIES -I$PATH_INC -c "$PATH_SRC_CPP" -o "$PATH_OBJ_O"
done

# Gather all compiled object files and link the project.
PATHS_O=$(find "$PATH_OBJ" -type f -name "*.o")
g++ $COMPILE_VERSION $COMPILE_FLAGS $COMPILE_LIBRARIES $PATHS_O -o $PATH_EXE

$PATH_EXE