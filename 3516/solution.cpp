#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findClosest(int x, int y, int z) {
    // Compute the absolute distance from Person 1 (x) to Person 3 (z)
    int distance1 = abs(x - z);

    // Compute the absolute distance from Person 2 (y) to Person 3 (z)
    int distance2 = abs(y - z);

    // If distances are equal, both arrive at the same time
    if (distance1 == distance2) {
      return 0;
    }

    // If Person 1 is closer, return 1; otherwise, return 2
    return (distance1 < distance2) ? 1 : 2;
  }
};
