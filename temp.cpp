#include <iostream>
#include <map>
using namespace std;
int main() {
    // Creating a map
    map<int, string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";
    myMap[4] = "Four";
    myMap[5] = "Five";


    cout << "Method 1: Using Iterators\n";
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << ": " << it->second << "\n";
    }

    cout << "\nMethod 2: Range-based For Loop\n";
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    cout << "\nMethod 3: Using forEach Lambda\n";
    for_each(myMap.begin(), myMap.end(), [](const auto& pair) {
        cout << pair.first << ": " << pair.second << "\n";
    });

    cout << "\nMethod 4: Using Range-based For Loop with Structured Bindings\n";
    for (const auto& [key, value] : myMap) {
        cout << key << ": " << value << "\n";
    }

    return 0;
}
