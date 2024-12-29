#!/bin/bash

# Check if a commit message was provided
if [ -z "$1" ]; then
    echo "Error: No commit message provided."
    exit 1
fi

COMMIT_MESSAGE=$1

# Add all files to staging
git add .
if [ $? -ne 0 ]; then
    echo "Error: Failed to add files to staging."
    exit 1
fi

# Commit with the provided message
git commit -m "$COMMIT_MESSAGE"
if [ $? -ne 0 ]; then
    echo "Error: Failed to commit changes."
    exit 1
fi

# Clean up git ignored files
git clean -Xfd

echo "Cleaned up ignored files."

# Push the changes
NO_PUSH=$2
if [ "$NO_PUSH" = "--no-push" ]; then
    echo "Changes added and committed successfully."
    echo "Push skipped."
    exit 0
fi

git push
if [ $? -ne 0 ]; then
    echo "Error: Failed to push changes."
    exit 1
fi

echo "Changes added, committed, and pushed successfully."
