#include "arithmetic.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        return 0; // Error: Division by zero
    }
    return a / b;
}

void bubbleSort(int* arr, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    bubbleSort(arr1, size1);
    
    bubbleSort(arr2, size2);

    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}
