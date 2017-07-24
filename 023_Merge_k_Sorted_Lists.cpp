/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //  O(k*n)  不是最优解法，最优解用优先队列或者堆
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())  return 0;
        ListNode* p1 = new ListNode(0);
        ListNode* p2 = p1;
        int min_index;
        while (p1)
        {
            min_index = 0;
            for (int i = 0; i < lists.size(); )
            {
                if (lists[i] == 0)  
                    lists.erase(lists.begin()+i);
                else
                {
                    min_index = lists[i]->val < lists[min_index]->val ? i : min_index;
                    ++i;
                }
            }
            if (!lists.empty())   
            {
                p1->next = lists[min_index];
                p1 = p1->next;
                lists[min_index] = lists[min_index]->next;
            }
            else    
                p1 = p1->next;
        }
        return p2->next;
    }
};