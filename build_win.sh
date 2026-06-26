# A simple build script to compile the project.
set -e

echo "Setting constants..."

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
# COMPILE_FLAGS="-O3 -s -flto -DARCH_X86__ -DRELEASE__ -ffreestanding -fno-exceptions -fno-rtti -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -nostdlib -nostartfiles -nodefaultlibs -static -no-pie"
COMPILE_FLAGS="-g3 -O0 -ffreestanding -fno-exceptions -fno-rtti -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -nostdlib -nostartfiles -nodefaultlibs -static -no-pie"
COMPILE_LIBRARIES=""

# Re-create the object directory.
rm -rf $PATH_OBJ
mkdir -p $PATH_OBJ

echo "Editing .clangd..."

# Create the .clangd file to ensure IDE-syntax works correctly.
cat <<EOF > ${PATH_PWD}/.clangd
CompileFlags:
    Add:
        - -std=c++23
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
        - -nostartfiles
        - -nodefaultlibs
        - -static
        - -no-pie
        - -DARCH_X86__
        - -DDEBUG__

Documentation:
  CommentFormat: Doxygen
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

    x86_64-w64-mingw32-g++ $COMPILE_VERSION $COMPILE_FLAGS $COMPILE_LIBRARIES -I$PATH_INC -c "$PATH_SRC_CPP" -o "$PATH_OBJ_O" -lkernel32
done
PATHS_CPP=$(find "$PATH_TST" -type f -name "*.cpp")
for PATH_TST_CPP in $PATHS_CPP; do
    PATH_REL_CPP="${PATH_TST_CPP#$PATH_TST}"
    PATH_OBJ_O="$PATH_OBJ${PATH_REL_CPP%.cpp}.o"
    PATH_SUB_OBJ="${PATH_OBJ_O%/*}"

    echo "  Compiling $PATH_REL_CPP..."

    mkdir -p "$PATH_SUB_OBJ"

    x86_64-w64-mingw32-g++ $COMPILE_VERSION $COMPILE_FLAGS $COMPILE_LIBRARIES -I$PATH_INC -c "$PATH_TST_CPP" -o "$PATH_OBJ_O" -lkernel32
done

echo "Linking project..."

# Gather all compiled object files and link the project.
PATHS_O=$(find "$PATH_OBJ" -type f -name "*.o")
x86_64-w64-mingw32-g++ $COMPILE_VERSION $COMPILE_FLAGS $COMPILE_LIBRARIES $PATHS_O -o $PATH_EXE -lkernel32

echo "Finished!"
echo "-----"

cp $PATH_EXE $HOME/vmshare/common.exe