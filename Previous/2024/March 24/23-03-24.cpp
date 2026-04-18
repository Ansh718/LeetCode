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
    ListNode *middle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *p1 = head;
        ListNode *p2 = NULL;
        ListNode *p3 = NULL;
        while (p1 != NULL)
        {
            p3 = p2;
            p2 = p1;
            p1 = p1->next;
            p2->next = p3;
        }
        return p2;
    }
    void reorderList(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
        {
            return;
        }
        ListNode *mid = middle(head);
        ListNode *mnext = reverse(mid->next);
        mid->next = NULL;
        ListNode *p1 = head;
        ListNode *p2 = mnext;
        ListNode *p3 = NULL;
        ListNode *p4 = NULL;
        while (p1 != NULL && p2 != NULL)
        {
            p3 = p1->next;
            p4 = p2->next;
            p1->next = p2;
            p2->next = p3;
            p1 = p3;
            p2 = p4;
        }
    }
};