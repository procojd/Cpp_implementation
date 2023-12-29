#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> myVector = {1, 2, 3, 4, 5};

    // 1. Using a For Loop
    cout << "Using a For Loop: ";
    for (int i = 0; i < myVector.size(); ++i) {
        cout << myVector[i] << " ";
    }
    cout << "\n";

    // 2. Using Range-based For Loop (C++11 and newer)
    cout << "Using Range-based For Loop: ";
    for (auto i : myVector) {
        cout << i << " ";
    }
    cout << "\n";

    // 3. Using Iterators
    cout << "Using Iterators: ";
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    // 4. Using Standard Algorithms (for_each)
    cout << "Using Standard Algorithms: ";
    for_each(myVector.begin(), myVector.end(), [](int element) {
        cout << element << " ";
    });
    cout << "\n";

    // 5. Using Enumeration (Index and Element)
    cout << "Using Enumeration: ";
    for (int i = 0; i < myVector.size(); ++i) {
        cout << myVector[i] << " ";
    }
    cout << "\n";

    return 0;
}
