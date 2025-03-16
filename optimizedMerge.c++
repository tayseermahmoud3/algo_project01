// optimized merge
#include <iostream>
#include <vector>
using namespace std;

// Optimized merge function using a single auxiliary array
void merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    // Merge two sorted subarrays into temp[]
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back to original array
    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

// Optimized recursive Merge Sort function
void mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort left and right halves
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);

        // Merge sorted halves
        merge(arr, temp, left, mid, right);
    }
}

// Wrapper function to call mergeSort with a single auxiliary array
void optimizedMergeSort(vector<int>& arr) {
    vector<int> temp(arr.size()); // Allocate temp array once
    mergeSort(arr, temp, 0, arr.size() - 1);
}

// Test the optimized merge sort
int main() {
    vector<int> arr = {4, 1, 3, 9, 7, 6, 8, 2, 5};

    cout << "Original array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    optimizedMergeSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;

    return 0;
}