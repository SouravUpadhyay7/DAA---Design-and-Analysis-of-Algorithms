#include <stdio.h>

// Structure to hold min and max values
struct Pair {
    int min;
    int max;
};

// Function to find min and max using Divide and Conquer
struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair result, left, right;
    
    // Base Case: If only one element
    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    // Base Case: If two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // Divide the array into two halves
    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Conquer: Find overall min and max
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int arr[] = {3, 5, 1, 8, 2, 9, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Pair result = findMinMax(arr, 0, n - 1);

    printf("Minimum Element: %d\n", result.min);
    printf("Maximum Element: %d\n", result.max);

    return 0;
}

