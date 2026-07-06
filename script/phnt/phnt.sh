set -e

readonly PATH_PARSER="script/nt/Parser.cpp"
readonly PATH_BIN="script/bin/nt"
readonly PATH_PHNT="$PATH_BIN/phnt"
readonly PATH_OUT="$PATH_BIN/Main.out"

mkdir -p "$PATH_BIN"

# git clone https://github.com/apple-oss-distributions/xnu.git /path/to/folder
git clone "https://github.com/winsiderss/phnt.git" "$PATH_PHNT"

clang++ "$PATH_PARSER" -std=c++23 -lclang -o "$PATH_OUT"
$PATH_OUT