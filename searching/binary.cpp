#include <iostream>
#include <vector>
using namespace std;
// Binary search function
bool binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    if (binarySearch(arr, target))
        cout << target << " found in the array.\n";
    else
        cout << target << " not found in the array.\n";

    return 0;
}
