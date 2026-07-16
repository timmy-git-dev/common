$ErrorActionPreference = "Stop"

Write-Host "Setting constants..."

# Paths
$PATH_PWD = Get-Location
$PATH_SRC = Join-Path $PATH_PWD "src"
$PATH_TST = Join-Path $PATH_PWD "test"
$PATH_INC = Join-Path $PATH_PWD "inc"
$PATH_BIN = Join-Path $PATH_PWD "bin"
$PATH_OBJ = Join-Path $PATH_BIN "obj"
$PATH_EXE = Join-Path $PATH_BIN "common.exe"

# Flags
$COMPILE_VERSION = "-std=c++23"
$FLAGS_BOTH = "-g3", "-O0", "-ffreestanding"
$FLAGS_COMP = "-fno-exceptions", "-fno-rtti", "-fno-stack-protector", "-fno-asynchronous-unwind-tables", "-fno-unwind-tables"
$FLAGS_LINK = "-nostdlib", "-static"

# Recreate object directory
Remove-Item -Recurse -Force $PATH_OBJ -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Force $PATH_OBJ | Out-Null

Write-Host "Editing .clangd..."

@"
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
"@ | Set-Content -Path (Join-Path $PATH_PWD ".clangd") -Encoding UTF8

Write-Host "Compiling objects..."

function Compile-Files($basePath)
{
    Get-ChildItem $basePath -Recurse -Filter *.cpp | ForEach-Object {

        $src = $_.FullName
        $rel = $src.Substring($basePath.Length)
        $obj = Join-Path $PATH_OBJ ($rel -replace "\.cpp$", ".o")
        $objDir = Split-Path $obj -Parent

        Write-Host "  Compiling $rel"

        New-Item -ItemType Directory -Force $objDir | Out-Null

        & gcc `
            $COMPILE_VERSION `
            @FLAGS_BOTH `
            @FLAGS_COMP `
            "-I$PATH_INC" `
            -c $src `
            -o $obj
    }
}

Compile-Files $PATH_SRC
Compile-Files $PATH_TST

Write-Host "Linking project..."

$objects = Get-ChildItem $PATH_OBJ -Recurse -Filter *.o | ForEach-Object { $_.FullName }

& gcc `
    $COMPILE_VERSION `
    @FLAGS_BOTH `
    @FLAGS_LINK `
    $objects `
    -o $PATH_EXE `
    -lntdll `
    -e _start

Write-Host "Finished!"
Write-Host "-----"

& $PATH_EXE