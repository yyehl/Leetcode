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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)    return NULL;
        ListNode *ret = new ListNode(0);
        ListNode *cur = ret;
        bool carry = 0;
        int l1n, l2n, sum;
        while (l1 || l2 || carry)
        {
            l1n = l1 ? l1->val : 0;
            l2n = l2 ? l2->val : 0;
            sum = l1n + l2n + carry;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carry = sum > 9 ? 1 : 0;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return ret->next;
    }
};