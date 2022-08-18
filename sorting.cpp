#include <iostream>
#include <algorithm>

using namespace std;
// insertionsort
void insertionsort(int n, int array[])
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (array[j] < array[j - 1] && j >= 1)
        {
            swap(array[j], array[j - 1]);
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
// selectionsort
void selectionsort(int n, int array[])
{

    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {

            if (array[index] > array[j])
            {
                index = j;
            }
            if (index != i)
                swap(array[index], array[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
// bubblesort
void bubblesort(int n, int array[])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int array[n];
    // int *array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    insertionsort(n, array);
    selectionsort(n, array);
    bubblesort(n, array);
    return 0;
}