#!/bin/bash

# Function to add header guard to a file
add_header_guard() {
    FILE=$1
    GUARD_NAME=$(echo "$FILE" | tr '/.' '_' | tr '[:lower:]' '[:upper:]')_H

    # Check if the file already has a header guard
    if ! grep -q "#ifndef $GUARD_NAME" "$FILE"; then
        echo "Adding header guard to $FILE"
        # Add header guard to the file
        sed -i.bak "1i#ifndef $GUARD_NAME\n#define $GUARD_NAME\n" "$FILE"
        echo -e "\n#endif // $GUARD_NAME" >> "$FILE"
        rm "${FILE}.bak"
    else
        echo "Header guard already exists in $FILE"
    fi
}

# Find all header files and add header guards
find . -type f -name "*.hpp" -o -name "*.h" | while read -r FILE; do
    add_header_guard "$FILE"
done
