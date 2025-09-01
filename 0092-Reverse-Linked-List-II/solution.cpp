struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       // create a dummy node
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // move prev to one node before left
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // reverse sublist
        ListNode* curr = prev->next;
        ListNode* next;
        for (int i = 0; i < right - left; i++) {
            next = curr->next;  // store next node
            curr->next = next->next;    // detach next
            next->next = prev->next;    // move next to front of sublist
            prev->next = next;          // connect prev to moved node
        }
        // return new head
        return dummy.next;
    }
};