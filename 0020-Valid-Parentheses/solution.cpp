#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Stack to store opening brackets

        for (char c : s) {
            // If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // If stack is empty, no opening bracket to match
                if (st.empty()) return false;

                char top = st.top(); // Get the top element
                st.pop(); // Remove it from stack

                // Check if the current closing bracket matches the top
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false; // Mismatch found
                }
            }
        }

        // If stack is empty, all brackets matched correctly
        return st.empty();
    }
};