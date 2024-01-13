
#include <iostream>
#include <vector>
using namespace std;
// Partition the array into two halves and return the pivot index
int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[end];  // Choose the last element as the pivot
    int i = start - 1;        // Index of the smaller element

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    return i + 1;
}

// Recursive function to perform quicksort
void quickSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int pivot_index = partition(arr, start, end);

        quickSort(arr, start, pivot_index - 1);
        quickSort(arr, pivot_index + 1, end);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arrSize = arr.size();

    cout << "Original array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";

    quickSort(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
