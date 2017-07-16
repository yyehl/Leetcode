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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)   return head;
        else if (head->next == NULL)     return head;
        else ;
        
        ListNode* ptr = head;
        ListNode* last_ptr = ptr;
        ptr = ptr->next;
        while (ptr != NULL)
        {
            if (ptr->val == last_ptr->val)
            {
                last_ptr->next = ptr->next;
                ptr = ptr->next;
            }
            else 
            {
                last_ptr = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
};