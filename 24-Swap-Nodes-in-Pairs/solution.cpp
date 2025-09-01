
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // create a dummy
        ListNode dummy(0);
        dummy.next = head; // remember, you use . to access an object not ->
        ListNode *prev = &dummy;

        while (prev->next && prev->next->next)
        {
            ListNode *first = prev->next;
            ListNode *second = first->next;

            // swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // move prev two nodes ahead
            prev = first;
        }
        return dummy.next;
    }
};