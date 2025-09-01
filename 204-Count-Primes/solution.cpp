#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // assume all primes initially
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        // Loop from 2 to sqrt(n)
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) { // If i is prime
                // Mark all multiples of i as non-prime
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // get the count of all numbers still marked
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Number of primes less than " << n << " is " << sol.countPrimes(n) << endl;
    return 0;
}
