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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)   return NULL;
        else if (l1 == NULL)    return l2;
        else if (l2 == NULL)    return l1;
        else ;
        
        ListNode* ret;
        if (l1->val <= l2->val)
        {
            ret = l1;
            l1 = l1->next;
        }
        else 
        {
            ret = l2;
            l2 = l2->next;
        }
        ListNode* ptr = ret;
        
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                ptr->next = l1;
                ptr = ptr->next;
                l1 = l1->next;
            }
            else 
            {
                ptr->next = l2;
                ptr = ptr->next;
                l2 = l2->next;
            }
        }
        if (l1 != NULL)
            ptr->next = l1;
        else
            ptr->next = l2;
        
        return ret;
    }
};