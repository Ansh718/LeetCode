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
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *s = head;
        ListNode *f = head;
        ListNode *pr = NULL;
        while (f != NULL && f->next != NULL)
        {
            f = f->next->next;
            ListNode *ns = s->next;
            s->next = pr;
            pr = s;
            s = ns;
        }
        if (f != NULL)
        {
            s = s->next;
        }
        while (pr != NULL && s != NULL)
        {
            if (pr->val != s->val)
            {
                return false;
            }
            pr = pr->next;
            s = s->next;
        }
        return true;
    }
};