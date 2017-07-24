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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)  return head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p1 && n--)   p1 = p1->next;
        if (!p1 && n == 0)  return head->next;
        if (!p1)    return head;
        while (p1->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};