// iterative merge sort
#include <iostream>
#include <vector>
using namespace std;

// Helper function to merge two sorted portions of the vector
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors for left and right subarrays
    vector<int> arr1(n1), arr2(n2);

    // Copy data to temporary vectors
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        arr2[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the temp vectors back into arr
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1[] if any
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2[] if any
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

// Iterative Merge Sort function
void mergeSort(vector<int>& arr) {
    int n = arr.size();

    // Iterate through subarrays of increasing size
    for (int currSize = 1; currSize < n; currSize *= 2) { // Corrected condition
        // Pick starting points of different subarrays of current size
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            // Find mid and right end points of subarrays to be merged
            int mid = min(leftStart + currSize - 1, n - 1);
            int rightEnd = min(leftStart + 2 * currSize - 1, n - 1);

            // Merge the subarrays arr[leftStart...mid] and arr[mid+1...rightEnd]
            merge(arr, leftStart, mid, rightEnd);
        }
    }
}

int main() {
    vector<int> arr = {4, 1, 3, 9, 7};

    cout << "Original array: ";
    for (auto val : arr) 
        cout << val << " ";
    cout << endl;

    mergeSort(arr);

    cout << "Sorted array: ";
    for (auto val : arr) 
        cout << val << " ";
    cout << endl;

    return 0;
}