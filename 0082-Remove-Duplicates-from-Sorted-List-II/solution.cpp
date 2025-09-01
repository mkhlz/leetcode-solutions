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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // while head exists
        while (head) {
            // check if current is start of duplicates
            if (head->next && head->val == head->next->val) {
                // skip all dups
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                // join prev with node after dups
                prev->next = head->next;
            } else {
                // otherwise move prev
                prev = head;
            }
            head = head->next;
        }
        return dummy.next;
    }
};