set -e

# Set constants.
readonly LINK_REPO="https://syscalls.mebeim.net/db"
readonly LINK_ARM="$LINK_REPO/arm64/64/aarch64/latest/table.json"
readonly LINK_X86="$LINK_REPO/x86/64/x64/latest/table.json"

readonly PATH_OUT_ID="inc/system/syscall/ID.hpp"
readonly PATH_OUT_CALL="inc/system/syscall/Call.hpp"
readonly PATH_BIN="script/bin"
readonly PATH_ARM="$PATH_BIN/arm.json"
readonly PATH_X86="$PATH_BIN/x86.json"

readonly DEF_ARM="CMN_SYSTEM_ARCH_ARM64"
readonly DEF_X86="CMN_SYSTEM_ARCH_X64"

# Ensure paths & download syscall tables.
mkdir -p $PATH_BIN

curl -s -L "$LINK_ARM" -o $PATH_ARM
curl -s -L "$LINK_X86" -o $PATH_X86

# Define helper funcs.
parse_syscall_table()
{
    json="$1"

    jq -r '
        .syscalls[] |
        [
            .name,
            .index,
            (.signature | join(", ")),
            (.signature | map("(long)" + (sub("^.* "; "") | sub("^\\*+"; ""))) | join(", "))
        ] |
        join("|")
    ' "$json"
}
def_syscall_indices()
{
    syscalls="$1"
    abi="$2"

    printf "    #if $2\n"
    while IFS= read -r syscall; do
        IFS='|' read -r name index _ _ <<< "$syscall"
        [[ "$ignored_names" == *$'\n'"$name"$'\n'* ]] && continue

        printf "    #define %-24s % 3s\n" "${name^^}" "$index"
    done <<< "$syscalls"
    printf "    #endif\n"
}
def_syscall_funcs()
{
    syscalls="$1"
    abi="$2"

    while IFS= read -r syscall; do
        IFS='|' read -r name _ signature params <<< "$syscall"
        [[ "$ignored_names" == *$'\n'"$name"$'\n'* ]] && continue

        if [[ "$params" == "" ]]; then
            printf "    inline long %-24s(%s) {return syscall(%s);};\n" "$name" "$signature" "${name^^}"
        else
            printf "    inline long %-24s(%s) {return syscall(%s, %s);};\n" "$name" "$signature" "${name^^}" "$params"
        fi

    done <<< "$syscalls"
}

# Parse syscalls.
readonly arm_syscalls="$(parse_syscall_table "$PATH_ARM" | sort)"
readonly x86_syscalls="$(parse_syscall_table "$PATH_X86" | sort)"
readonly ignored_names="$(cut -d '|' -f1 <<< "$arm_syscalls"$'\n'"$x86_syscalls" | sort | uniq -c | awk '$1 != 2 { print $2 }')"

# Write syscalls to file.
printf '// AUTO-GENERATED SCRIPT
#pragma once
#include "system/platform/Arch.hpp"

namespace cmn::system::syscall
{
' > "$PATH_OUT_ID"
printf '// AUTO-GENERATED SCRIPT
#pragma once
#include "system/syscall/Func.hpp"
#include "system/syscall/ID.hpp"
#include "system/syscall/Type.hpp"

namespace cmn::system::syscall
{
' > "$PATH_OUT_CALL"

def_syscall_indices "$arm_syscalls" "$DEF_ARM" >> "$PATH_OUT_ID"
def_syscall_indices "$x86_syscalls" "$DEF_X86" >> "$PATH_OUT_ID"
printf '}' >> "$PATH_OUT_ID"

def_syscall_funcs "$arm_syscalls" >> "$PATH_OUT_CALL"
printf '}' >> "$PATH_OUT_CALL"