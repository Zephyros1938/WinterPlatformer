#!/bin/bash

LIBRARIES_DIR="src"                   # the directory where the libraries are located
COMPILED_DIR="compiled"      # where the compiled libraries go
TO_COMPILE="main"                 # what needs to be compiled - seperate with spaces
PURGE_LIBRARIES=1                           # removes all the compiled libraries before compilation
SHOW_TO_COMPILE=1                           # shows what needs to be compiled
SHOW_COMPILED=1                             # shows what was compiled

if [ $PURGE_LIBRARIES == 1 ]; then
    rm -rf $COMPILED_DIR/*
    echo "[ INFO    ] Removed all compiled libraries."
fi

if [ $SHOW_TO_COMPILE == 1 ]; then
    echo "[ INFO    ] To Compile:"
    for item in $TO_COMPILE; do
        echo "[ INFO    ]  - $item"
    done
fi

for item in $TO_COMPILE; do
    echo "[ INFO    ] Compile $item"

    echo "[ INFO    ]  Start compile Linux libraries"
    echo "[ COMPILE ]   Compile $item"
    g++ -o $COMPILED_DIR/$item $LIBRARIES_DIR/$item.cpp -lGL -lglfw -lglm
    if [ ! -f $COMPILED_DIR/$item ]; then
        echo "[ ERROR   ] Failed to compile object file ($item)."
        exit 1
    fi
done

print_tree() {
    local dir="$1"
    local prefix="$2"

    local entries=("$dir"/*)
    local count=${#entries[@]}
    local i=0

    for entry in "${entries[@]}"; do
        ((i++))
        local name="$(basename "$entry")"
        local connector="├──"
        if [ "$i" -eq "$count" ]; then
            connector="└──"
        fi
        echo "${prefix}${connector} ${name}"
        if [ -d "$entry" ]; then
            local new_prefix="${prefix}│   "
            if [ "$i" -eq "$count" ]; then
                new_prefix="${prefix}    "
            fi
            print_tree "$entry" "$new_prefix"
        fi
    done
}

if [ $SHOW_COMPILED == 1 ]; then
    TREE=$(echo "$COMPILED_DIR" && print_tree "$COMPILED_DIR" "")
    echo "$TREE"
fi

echo "[ INFO    ] Done!"
