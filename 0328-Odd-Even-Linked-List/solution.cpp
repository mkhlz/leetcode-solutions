#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* odd = head; // start from 1st node
        ListNode* even = head->next; // start from 2nd node
        ListNode* evenHead = even; // keep track of even list head
        while (even && even->next) {
            odd->next = even->next; // link odd to next node
            odd = odd->next; // move odd forward
            even->next = odd->next; // link even to next node
            even = even->next; // move even forward
        }
        odd->next = evenHead; // attach even list after odd
        return head;
    }
};