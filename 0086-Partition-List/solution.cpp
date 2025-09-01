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
    ListNode* partition(ListNode* head, int x) {
        // The idea is to maintain two lists, one after head and
        // one before head
        ListNode before_head(0);
        ListNode after_head(0);
        ListNode* before = &before_head;
        ListNode* after = &after_head;

        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            if (curr->val < x) {
                before->next = curr;
                before = before->next;
            } else {
                after->next = curr;
                after = after->next;
            }
        }
        after->next = nullptr;
        before->next = after_head.next;

        return before_head.next;
    }
};