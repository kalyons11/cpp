#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <file_name> <function_name>"
    exit 1
fi

FILE_NAME=$1
FUNCTION_NAME=$2

# Create the .hpp file
cat <<EOL > "${FILE_NAME}.hpp"
void ${FUNCTION_NAME}();
EOL

# Create the .cpp file
cat <<EOL > "${FILE_NAME}.cpp"
#include <iostream>

#include "$(basename "${FILE_NAME}").hpp"

void ${FUNCTION_NAME}() {
    // TODO: Implement ${FUNCTION_NAME}
    std::cout << "Function ${FUNCTION_NAME}() has been called." << '\n';
}
EOL

./scripts/add_header_guards.sh "${FILE_NAME}.hpp"

echo "Files ${FILE_NAME}.hpp and ${FILE_NAME}.cpp have been created."

# Find the main.cpp file in the same directory as FILE_NAME
MAIN_CPP_DIR=$(dirname "${FILE_NAME}")
MAIN_CPP_FILE="${MAIN_CPP_DIR}/main.cpp"

if [ -f "${MAIN_CPP_FILE}" ]; then
    # Insert #include for the header file
    sed -i '' "1i\\
#include \"$(basename "${FILE_NAME}").hpp\"
" "${MAIN_CPP_FILE}"

    # Call the function right before return 0; at the end of main()
    sed -i '' "/return 0;/i\\
    ${FUNCTION_NAME}();
" "${MAIN_CPP_FILE}"

    echo "Included $(basename "${FILE_NAME}").hpp in ${MAIN_CPP_FILE} and called ${FUNCTION_NAME}() in main()."
else
    echo "main.cpp not found in ${MAIN_CPP_DIR}."
fi

