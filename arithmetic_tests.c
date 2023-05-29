#include <CUnit/Basic.h>
#include "arithmetic.h" // Header file for the arithmetic module being tested
#include <stdio.h>
#include <stdlib.h>

// Global variables
int *data = NULL; // Placeholder for any global test data

// Test suite initialization function
int init_suite() {
    // Allocate memory for test data
    data = (int*)malloc(sizeof(int));
    if (data == NULL) {
        return -1; // Error: Failed to allocate memory
    }

    // Initialize test data
    *data = 42;

    // Additional setup steps can be performed here if needed

    return 0;
}

// Test suite cleanup function
int clean_suite() {
    // Cleanup test data
    free(data);

    // Additional cleanup steps can be performed here if needed

    return 0;
}

// Test function to verify the addition operation
void test_addition() {
    CU_ASSERT_EQUAL(add(2, 3), 5);
    CU_ASSERT_EQUAL(add(-1, 5), 4);
    CU_ASSERT_EQUAL(add(0, 0), 0);
}

// Test function to verify the subtraction operation
void test_subtraction() {
    CU_ASSERT_EQUAL(subtract(5, 3), 2);
    CU_ASSERT_EQUAL(subtract(10, 5), 5);
    CU_ASSERT_EQUAL(subtract(0, 0), 0);
}

// Test function to verify the multiplication operation
void test_multiplication() {
    CU_ASSERT_EQUAL(multiply(2, 3), 6);
    CU_ASSERT_EQUAL(multiply(-1, 5), -5);
    CU_ASSERT_EQUAL(multiply(0, 10), 0);
}

// Test function to verify the division operation
void test_division() {
    CU_ASSERT_EQUAL(divide(10, 2), 5);
    CU_ASSERT_EQUAL(divide(7, 0), 0); // Error: Division by zero
    CU_ASSERT_EQUAL(divide(0, 5), 0);
}

int main() {
    CU_pSuite suite = NULL;

    // Initialize the CUnit test registry
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    // Create a test suite
    suite = CU_add_suite("Arithmetic Suite", init_suite, clean_suite);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test functions to the test suite
    if (CU_add_test(suite, "Addition", test_addition) == NULL ||
        CU_add_test(suite, "Subtraction", test_subtraction) == NULL ||
        CU_add_test(suite, "Multiplication", test_multiplication) == NULL ||
        CU_add_test(suite, "Division", test_division) == NULL) {
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
