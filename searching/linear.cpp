#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& vect, int target) {
    for (int i = 0; i < vect.size(); ++i) {
        if (vect[i] == target) {
            return i;  // Return the index of the target if found
        }
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    vector<int> vect = {12, 11, 13, 5, 6, 7};
    int target = 6;

    int result = linearSearch(vect, target);

    if (result != -1) {
        cout << "Target found at index " << result << "\n";
    } else {
        cout << "Target not found in the vecttor\n";
    }

    return 0;
}
