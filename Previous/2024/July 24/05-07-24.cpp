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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        ListNode *ptr = head;
        ListNode *prev = NULL;
        int miN = INT_MAX;
        int first = -1;
        int last = -1;
        int pos = 1;
        vector<int> result(2, -1);
        while (ptr && ptr->next)
        {
            if (prev && ((ptr->val > prev->val && ptr->val > ptr->next->val) || (ptr->val < prev->val && ptr->val < ptr->next->val)))
            {
                if (first == -1)
                {
                    first = pos;
                }
                else
                {
                    miN = min(miN, pos - last);
                }
                last = pos;
            }
            prev = ptr;
            ptr = ptr->next;
            pos++;
        }
        if (first != -1 && last != -1 && first != last)
        {
            result[0] = miN;
            result[1] = last - first;
        }
        return result;
    }
};