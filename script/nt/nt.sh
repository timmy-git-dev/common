set -e

readonly PATH_PARSER="script/nt/Parser.cpp"
readonly PATH_BIN="script/bin/nt"
readonly PATH_OUT="$PATH_BIN/Main.out"

mkdir -p "$PATH_BIN"

clang++ "$PATH_PARSER" -std=c++23 -lclang -o "$PATH_OUT"
$PATH_OUT