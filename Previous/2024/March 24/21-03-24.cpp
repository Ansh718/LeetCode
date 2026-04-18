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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *ptr1 = head;
        ListNode *ptr2 = NULL;
        ListNode *ptr3 = NULL;
        while (ptr1 != NULL)
        {
            ptr3 = ptr2;
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            ptr2->next = ptr3;
        }
        return ptr2;
    }
};