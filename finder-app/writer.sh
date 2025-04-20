#!/bin/bash

# Check if both arguments are provided
if [ $# -lt 2 ]; then
  echo "Error: Missing arguments."
  echo "Usage: $0 <writefile> <writestr>"
  exit 1
fi

writefile=$1
writestr=$2

# Extract the directory path from the file path
dirpath=$(dirname "$writefile")

# Create the directory path if it doesn't exist
mkdir -p "$dirpath"
if [ $? -ne 0 ]; then
  echo "Error: Failed to create directory '$dirpath'."
  exit 1
fi

# Create or overwrite the file with the specified content
echo "$writestr" > "$writefile"
if [ $? -ne 0 ]; then
  echo "Error: Failed to write to file '$writefile'."
  exit 1
fi
