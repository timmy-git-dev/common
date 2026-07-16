param(
    [string]$TARGET
)

$ErrorActionPreference = "Stop"

Write-Host "Setting constants..."

$ROOT = $PWD
$SRC = "$ROOT/src"
$TST = "$ROOT/test"
$INC = "$ROOT/inc"

$BIN = "$ROOT/bin"
$OBJ = "$BIN/obj"
$EXE = "$BIN/common.exe"


$COMPILE_VERSION = "-std=c++23"

$FLAGS_BOTH = @(
    "-g3"
    "-O0"
    "-ffreestanding"
)

$FLAGS_COMP = @(
    "-fno-exceptions"
    "-fno-rtti"
    "-fno-stack-protector"
    "-fno-asynchronous-unwind-tables"
    "-fno-unwind-tables"
)

$FLAGS_LINK = @(
    "-nostdlib"
    "-static"
)

$INCLUDE_FLAGS = @(
    "-I$INC"
)


Remove-Item -Recurse -Force $OBJ -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Force $OBJ | Out-Null


Write-Host "Editing .clangd..."

@"
CompileFlags:
    Add:
        - -std=c++23
        - --target=$TARGET
        - -I$INC
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
        - -static
        - -no-pie
"@ | Set-Content "$ROOT/.clangd"


function CompileDir {
    param(
        [string]$DIR
    )

    Get-ChildItem $DIR -Recurse -File -Filter "*.cpp" | ForEach-Object {
        $CPP = $_.FullName

        $REL = $CPP.Substring($DIR.Length).TrimStart("\","/")
        $OBJ_PATH = Join-Path $OBJ ($REL -replace "\.cpp$", ".o")

        Write-Host "  Compiling $REL..."

        New-Item -ItemType Directory -Force -Path (Split-Path $OBJ_PATH) | Out-Null

        & clang++ `
            "--target=$TARGET" `
            $COMPILE_VERSION `
            $FLAGS_BOTH `
            $FLAGS_COMP `
            $INCLUDE_FLAGS `
            -c $CPP `
            -o $OBJ_PATH

        if ($LASTEXITCODE -ne 0) {
            exit $LASTEXITCODE
        }
    }
}


Write-Host "Compiling..."

CompileDir $SRC
CompileDir $TST


Write-Host "Linking project..."

$OBJECTS = Get-ChildItem $OBJ -Recurse -File -Filter "*.o" |
    ForEach-Object { $_.FullName }

& clang++ `
    "--target=$TARGET" `
    $COMPILE_VERSION `
    $FLAGS_BOTH `
    $FLAGS_LINK `
    $OBJECTS `
    -o $EXE `
    "-lntdll" `
    "-e" `
    "start__"

if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}


Write-Host "-----"

$env:WINEDEBUG = "-all"

& $EXE
$RESULT = $LASTEXITCODE

Write-Host "-----"

Write-Host $RESULT
exit $RESULT