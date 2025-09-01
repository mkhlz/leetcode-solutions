
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);          // create a dummy node; starting point of merged list
        ListNode *current = &dummy; // current will point to the last node

        // traverse both the lists until one becomes null
        while (l1 && l2)
        {
            // compare both the values of two lists
            if (l1->val <= l2->val)
            {
                // if l1's value is smaller or equal, attach l1 to merged list
                current->next = l1;
                // move l1 to next node
                l1 = l1->next;
                // if l2's value is smaller of equal, attach l2 to merged list
            }
            else
            {
                current->next = l2;
                // move l2 to next node
                l2 = l2->next;
            }
            // move current to newly added node
            current = current->next;
        }

        // at this point, either l1 or l2 are null
        // therefore, attach remaining to the merged list
        if (l1)
            current->next = l1;
        if (l2)
            current->next = l2;
        // merged list starts from dummy
        return dummy.next;
    }
};