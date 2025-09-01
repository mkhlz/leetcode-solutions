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
    ListNode* rotateRight(ListNode* head, int k) {
        // edge cases
        if (!head || !head->next || k==0) {
            return head;
        }

        // set head to current
        ListNode* current = head;
        
        // get the length and last node
        int length = 1;
        while (current -> next) {
            current = current->next;
            length++;
        }

        // set that element as head
        current->next = head;

        int stepsToNewHead = length - k % length;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};