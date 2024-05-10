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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    ListNode *removeNodes(ListNode *head)
    {
        ListNode *reversedHead = reverse(head);
        int max_val = INT_MIN;
        ListNode *current = reversedHead;
        while (current)
        {
            max_val = max(max_val, current->val);
            if (current->next && current->next->val < max_val)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        ListNode *newHead = reverse(reversedHead);
        return newHead;
    }
};
