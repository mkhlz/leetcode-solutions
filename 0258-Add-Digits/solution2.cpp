#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;           // edge case
        return 1 + (num - 1) % 9;         // digital root formula
    }
};

int main() {
    Solution sol;
    int n = 38;
    cout << "Result: " << sol.addDigits(n) << endl; // Output: 2
    return 0;
}
