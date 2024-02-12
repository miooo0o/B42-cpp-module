#!/bin/bash

# original log
file1="19920104_091532.log"
# result
file2="res.log"

# Remove date information and save to temporary files
sed 's/^[^;]*;//' "$file1" > temp_file1
sed 's/^[^;]*;//' "$file2" > temp_file2

# Compare the two files
diff temp_file1 temp_file2

# Check the exit status of diff
if [ $? -eq 0 ]; then
    echo "Files are identical (ignoring date)."
else
    echo "Files are different (ignoring date)."
fi

# Remove temporary files
rm temp_file1 temp_file2