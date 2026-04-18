/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        if (head->val >= 5)
        {
            head = new ListNode(0, head);
        }
        for (ListNode *curr = head; curr != nullptr; curr = curr->next)
        {
            curr->val *= 2;
            curr->val %= 10;
            if (curr->next && curr->next->val >= 5)
            {
                curr->val++;
            }
        }
        return head;
    }
};