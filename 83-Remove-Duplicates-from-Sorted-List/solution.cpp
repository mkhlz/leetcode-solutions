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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current && current->next) {
            // skip dup
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                // move forward if no dup
                current = current->next;
            }
        }
        return head;
    }
};