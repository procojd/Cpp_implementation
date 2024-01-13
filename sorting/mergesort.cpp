
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<int> start_array(n1);
    vector<int> end_array(n2);
    
    for (int i = 0; i < n1; i++)
        start_array[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        end_array[j] = arr[mid + 1 + j];

    int i = 0; int j = 0; int k = start;

    while (i < n1 && j < n2) {
        if (start_array[i] <= end_array[j]) {
            arr[k] = start_array[i];
            i++;
        } else {
            arr[k] = end_array[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = start_array[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = end_array[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;//split

        mergeSort(arr, start, mid);//recurse
        mergeSort(arr, mid + 1, end);//recurse

        merge(arr, start, mid, end);//merge
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

    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
