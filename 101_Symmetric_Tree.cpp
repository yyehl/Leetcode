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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))    return true;
        
        queue<TreeNode*> qt;
        qt.push(root);
        qt.push(root);
        
        while (!qt.empty())
        {
            TreeNode* r1 = qt.front();
            qt.pop();
            TreeNode* r2 = qt.front();
            qt.pop();
            if (r1 == NULL && r2 == NULL)   continue;
            else if (r1 == NULL || r2 == NULL)  return false;
            else if (r1->val != r2->val)    return false;
            else
            {
                qt.push(r1->left);
                qt.push(r2->right);
                qt.push(r1->right);
                qt.push(r2->left);
            }
        }
        
        return true;
    }
};