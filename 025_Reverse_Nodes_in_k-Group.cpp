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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 0 || k == 1)   return head;
        ListNode* ret = new ListNode(0);
        pair<ListNode*, ListNode*> pl = foo(head, k);
        ret->next = pl.first;
        head = pl.second;
        while (pl.first != pl.second)
        {
            pl = foo(head->next, k);
            head->next = pl.first;
            head = pl.second;
        }
        return ret->next;
    }
    pair<ListNode*, ListNode*> foo(ListNode* head, int k)
    {
        vector<ListNode*> vl;
        ListNode* p = head;
        while (k--)
        {
            if (p)   
            {
                vl.push_back(p);
                p = p->next;
            }
            else
                return make_pair(head, head);
        }
        for (int i = 0;i < vl.size()/2; ++i)
        {
            ListNode* tmp = vl[i];
            vl[i] = vl[vl.size()-1-i];
            vl[vl.size()-1-i] = tmp;
        }
        vl[vl.size()-1]->next = vl[0]->next;
        for (int i = 0; i < vl.size()-1; i++)
            vl[i]->next = vl[i+1];
        return make_pair(vl[0], vl[vl.size()-1]);
    }
    
};