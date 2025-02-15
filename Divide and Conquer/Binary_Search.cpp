#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the key is present at mid
        if (arr[mid] == key)
            return mid;

        // If the key is smaller, search in the left subarray
        if (arr[mid] > key)
            return binarySearch(arr, left, mid - 1, key);

        // Otherwise, search in the right subarray
        return binarySearch(arr, mid + 1, right, key);
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 18, 20, 25}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}

