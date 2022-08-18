#include <iostream>
using namespace std;
// linear search
void linear(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            cout << "Target found at position " << i + 1 << endl;
        }
    }
}

// binary search
void binary(int arr[], int n, int target)
{
    int start = 0;
    int end = n;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            cout << "Target found at position " << mid + 1 << endl;
        if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
}
int main()
{
    int n;
    cout << "Enter the length of array";
    cin >> n;
    int array[n];

    // int *array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int target;
    cout << "Enter the target element";
    cin >> target;

    linear(array, n, target);
    binary(array, n, target);

    return 0;
}
