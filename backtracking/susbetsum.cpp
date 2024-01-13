#include <iostream>
#include <vector>

using namespace std;

// Function to check if a subset with the given sum exists using backtracking
bool isSubsetSum(vector<int>& set, int n, int sum, vector<int>& subset) {
    // Base cases
    if (sum == 0) {
        // Subset with the given sum found
        return true;
    }
    if (n == 0 && sum != 0) {
        // Subset with the given sum not possible
        return false;
    }
    // Exclude the last element and check the remaining subset
    if (set[n - 1] > sum) {
        return isSubsetSum(set, n - 1, sum, subset);
    }
    // Consider including or excluding the last element in the subset
    if (isSubsetSum(set, n - 1, sum, subset)) {
        return true;
    }
    subset.push_back(set[n - 1]);
    if (isSubsetSum(set, n - 1, sum - set[n - 1], subset)) {
        return true;
    }
    // If no subset is found, remove the last element from the current subset
    subset.pop_back();
    return false;
}

// Function to print the subset with the given sum
void printSubset(vector<int>& subset) {
    cout << "Subset: { ";
    for (int num : subset) {
        cout << num << " ";
    }
    cout << "}\n";
}

int main() {
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;

    vector<int> subset;

    if (isSubsetSum(set, set.size(), targetSum, subset)) {
        cout << "Subset with the sum " << targetSum << " exists.\n";
        printSubset(subset);
    } else {
        cout << "No subset with the sum " << targetSum << " exists.\n";
    }

    return 0;
}
