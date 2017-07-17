/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL)   return vector<vector<int>>(0, vector<int>(0));
        queue<TreeNode*> qt;
        vector<vector<int>> ret;
        vector<int> each_lev;
        int len = 0;
        qt.push(root);
        while (!qt.empty())
        {
            len = qt.size();
            each_lev.clear();
            while (len--)
            {
                if (qt.front()->left != NULL)   qt.push(qt.front()->left);
                if (qt.front()->right != NULL)  qt.push(qt.front()->right);
                each_lev.push_back(qt.front()->val);
                qt.pop();
            }
            ret.push_back(each_lev);
        }
        vector<vector<int>> tmp;
        for (int i = ret.size()-1; i >= 0; i--) 
            tmp.push_back(ret[i]);
        // reverse(ret.begin(), ret.end());
        
        return tmp;
    }
};