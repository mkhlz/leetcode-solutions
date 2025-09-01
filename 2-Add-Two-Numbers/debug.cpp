#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }

template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);          // dummy node to simplify code
        ListNode* current = &dummy; // pointer to build the result list
        int carry = 0;              // to store carry-over

while (l1 || l2 || carry) {
    int sum = carry;
    if (l1) {
        sum += l1->val;
        dbg("l1->val", l1->val);  // Debug print
        l1 = l1->next;
    }
    if (l2) {
        sum += l2->val;
        dbg("l2->val", l2->val);  // Debug print
        l2 = l2->next;
    }

    dbg(sum, carry);  // Debugging sum and carry
}

        return dummy.next; // skip dummy node
    }
};

// Optional: Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 342 + 465
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    printList(result); // Output: 7 -> 0 -> 8

    return 0;
}
