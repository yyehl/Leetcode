/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == 0 || head->next == 0)   return head;
        ListNode* ret = new ListNode(0);
        ret->next = foo(head);
        while (head)
        {
            head->next = foo(head->next);
            if (head->next == 0 || head->next->next == 0)
                break;
            else
                head = head->next->next;
        }
        return ret->next;
    }
    ListNode* foo(ListNode* head)
    {
        if (head == 0 || head->next == 0)   return head;
        else
        {
            ListNode* tmp = head->next;
            head->next = tmp->next;
            tmp->next = head;
            return tmp;
        }
    }
};