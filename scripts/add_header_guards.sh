#!/bin/bash

# Also rename to .hpp
find . -type f -name '*.h' -exec bash -c 'git mv "$0" "${0%.h}.hpp"' {} \;

# Replace any "include.h" with "include.hpp" in *.cpp files
find . -type f -name "*.cpp" -exec sed -i '' 's/\.h"/.hpp"/g' {} \;

# Function to add header guard to a file
add_header_guard() {
    FILE=$1
    GUARD_NAME=$(echo "$FILE" | tr '/.' '_' | tr '[:lower:]' '[:upper:]')_H

    # Check if the file already has a header guard
    if ! grep -q "#ifndef $GUARD_NAME" "$FILE"; then
        echo "Adding header guard to $FILE"
        # Add header guard to the file
        printf "#ifndef $GUARD_NAME\n#define $GUARD_NAME\n\n" | cat - "$FILE" > temp && mv temp "$FILE"
        echo -e "\n#endif // $GUARD_NAME" >> "$FILE"
    fi
}

# If arguments are provided, use them as the list of files
if [ "$#" -gt 0 ]; then
    FILES="$@"
else
    # Find all header files if no arguments are provided
    FILES=$(find . -type f -name "*.hpp" -o -name "*.h")
fi

# Add header guards to the specified files
for FILE in $FILES; do
    add_header_guard "$FILE"
done
