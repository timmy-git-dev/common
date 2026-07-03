set -e

readonly PATH_BIN="script/bin/nt"
readonly PATH_PHNT="$PATH_BIN/phnt.h"

mkdir -p "$PATH_BIN"

curl -s -L "$LINK_PHNT" -o "$PATH_PHNT"