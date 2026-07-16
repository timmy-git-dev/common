$ErrorActionPreference = "Stop"


$COMPILER = $args[0]
$TARGET = $args[1]

$CPP_STANDARD = "-std=c++23"
$ENTRY = "_start"

$ROOT = $PWD.Path
$SRC = "$ROOT/src"
$TST = "$ROOT/test"
$INC = "$ROOT/inc"

$BIN = "$ROOT/bin"
$OBJ = "$BIN/obj"
$EXE = "$BIN/common.exe"


$COMMON_FLAGS = @(
    $CPP_STANDARD
    "-g3"
    "-O0"
    "-ffreestanding"
)

$COMPILE_FLAGS = @(
    "-fno-exceptions"
    "-fno-rtti"
    "-fno-stack-protector"
    "-fno-asynchronous-unwind-tables"
    "-fno-unwind-tables"
)

$LINK_FLAGS = @(
    "-nostdlib"
    "-static"
)

$WARNING_FLAGS = @(
    "-Wall"
    "-Wextra"
    "-Wpedantic"
    "-Wunused-value"
)

$INCLUDE_FLAGS = @(
    "-I$INC"
)


function Compile-Dir {
    param (
        [string]$Dir
    )

    Get-ChildItem -Path $Dir -Recurse -File -Filter "*.cpp" | ForEach-Object {
        $cpp = $_.FullName
        $rel = $cpp.Substring($Dir.Length)
        $obj = "$OBJ$($rel -replace '\.cpp$', '.o')"

        Write-Host "  Compiling $rel..."

        New-Item -ItemType Directory -Force -Path (Split-Path $obj) | Out-Null

        & $COMPILER `
            @COMMON_FLAGS `
            @COMPILE_FLAGS `
            @INCLUDE_FLAGS `
            -c $cpp `
            -o $obj
    }
}


function Link-Project {
    Write-Host "Linking..."

    $objects = Get-ChildItem -Path $OBJ -Recurse -File -Filter "*.o" |
        ForEach-Object { $_.FullName }

    & $COMPILER `
        @COMMON_FLAGS `
        @LINK_FLAGS `
        $objects `
        -o $EXE `
        -e $ENTRY
}


function Write-Clangd {
    @"
CompileFlags:
    Add:
"@ | Set-Content "$ROOT/.clangd"

    @(
        "--target=$TARGET"
        $CPP_STANDARD
        $INCLUDE_FLAGS
        $WARNING_FLAGS
        $COMMON_FLAGS
        $COMPILE_FLAGS
        $LINK_FLAGS
    ) | ForEach-Object {
        Add-Content "$ROOT/.clangd" "        - $_"
    }
}


Remove-Item -Recurse -Force $BIN -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Force -Path $OBJ | Out-Null

Write-Clangd

Write-Host "Compiling..."
Compile-Dir $SRC
Compile-Dir $TST

Link-Project


Write-Host "-----"
& $EXE
$result = $LASTEXITCODE
Write-Host "-----"

Write-Host $result
exit $result