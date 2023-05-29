#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "arithmetic.h" // Header file for the arithmetic module being tested


void testMergeArrays() {
    int arr1[] = {3, 9, 5, 7, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);


    int arr2[] = {2, 10, 6, 8, 4};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int merged[size1 + size2];
    mergeArrays(arr1, size1, arr2, size2, merged);

    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < size1 + size2; i++) {
        CU_ASSERT_EQUAL_FATAL(merged[i], expected[i]);
    }
}

int main() {
    // Initialize the CUnit test registry
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Create a new test suite
    CU_pSuite suite = CU_add_suite("MergeArraysSuite", NULL, NULL);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test case to the suite
    if (CU_add_test(suite, "testMergeArrays", testMergeArrays) == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Clean up resources
    CU_cleanup_registry();

    return CU_get_error();
}
