#include <iostream>

// Function to find the minimum element in the array and return its index
int findMinIndex(int arr[], int start, int end) {
    int minIndex = start;
    for (int i = start + 1; i < end; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Recursive Assertion Sort function
void recursiveAssertionSort(int arr[], int size, int start = 0) {
    if (start == size) {
        return; // Base case: array is sorted
    }

    // Find the index of the minimum element in the unsorted portion
    int minIndex = findMinIndex(arr, start, size);

    // Swap the minimum element with the first element in the unsorted portion
    std::swap(arr[start], arr[minIndex]);

    // Recursively sort the rest of the array
    recursiveAssertionSort(arr, size, start + 1);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    recursiveAssertionSort(arr, size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
