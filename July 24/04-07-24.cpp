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
    ListNode *mergeNodes(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode *temp = head->next;
        int sum = 0;
        while (temp)
        {
            if (temp->val == 0)
            {
                prev->next = new ListNode(sum);
                prev = prev->next;
                sum = 0;
            }
            else
            {
                sum += temp->val;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};
