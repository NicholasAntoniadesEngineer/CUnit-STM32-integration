#!/bin/bash

#chmod +x build.sh

# Build the project (replace with your actual build command)
make

# Run the unit tests and capture the test results
./merge_array_tests -v -o test_results.xml

# Check the test results and exit with a non-zero status if any test fails
if grep -q 'FAILED' test_results.xml; then
    echo "Unit test failure detected. Build failed."
    exit 1
fi
