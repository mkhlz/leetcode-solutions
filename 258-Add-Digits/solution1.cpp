#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        // Keep looping until num is a single digit
        while (num >= 10) {
            int sum = 0;
            int temp = num;
            // Add all digits of num
            while (temp > 0) {
                sum += temp % 10;  // extract last digit
                temp /= 10;         // remove last digit
            }
            num = sum;  // update num with the sum of digits
        }
        return num;
    }
};

int main() {
    Solution sol;
    int n = 9999999;
    cout << "Result: " << sol.addDigits(n) << endl;
    return 0;
}
