#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareItems(const pair<int, int>& item1, const pair<int, int>& item2) {
    double valuePerWeight1 = (item1.second) / item1.first;
    double valuePerWeight2 = (item2.second) / item2.first;
    return valuePerWeight1 > valuePerWeight2;
}//just sorting the items not much.

double fractionalKnapsack(int capacity, vector<pair<int, int>>& items) {
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    for (const auto& item : items) {
        int weight = item.first;
        int value = item.second;

        if (capacity >= weight) {
            totalValue += value;
            capacity -= weight;
        } else {
            // Take a fraction of the item
            totalValue += (static_cast<double>(capacity) / weight) * value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n; // number of items
    cout << "Enter the number of items: ";
    cin >> n;

    vector<pair<int, int>> items; // pair of weight and value
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        int weight, value;
        cin >> weight >> value;
        items.push_back({weight, value});
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    double result = fractionalKnapsack(capacity, items);

    cout << "Maximum value in the knapsack: " << result << endl;

    return 0;
}
