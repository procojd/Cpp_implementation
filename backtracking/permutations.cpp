#include <iostream>
#include <vector>

using namespace std;

// Helper function to swap elements in a vector
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Backtracking function to generate all permutations
void generatePermutations(vector<int>& arr, int start, vector<vector<int>>& result) {
    if (start == arr.size() - 1) {
        // If we reached the end of the array, add the current permutation to the result
        result.push_back(arr);
        return;
    }

    for (int i = start; i < arr.size(); ++i) {
        // Swap the current element with each element to its right
        swap(arr, start, i);

        // Recursively generate permutations for the remaining elements
        generatePermutations(arr, start + 1, result);

        // Backtrack by undoing the swap
        swap(arr, start, i);
    }
}

int main() {
    // Example usage
    vector<int> elements = {1, 2, 3};
    vector<vector<int>> permutations;

    generatePermutations(elements, 0, permutations);

    // Print the generated permutations
    cout << "All Permutations:\n";
    for (const vector<int>& permutation : permutations) {
        cout << "[ ";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
