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
    bool isBalanced(TreeNode* root) {
        return balance_or_not(root) != -1;
    }
    
    int balance_or_not(TreeNode* root)
    {
        if (root == NULL)   return 0;
        int left = balance_or_not(root->left);
        if (left == -1)     return -1;
        int right = balance_or_not(root->right);
        if (right == -1)    return -1;
        if (abs(left - right) <= 1) return max(left, right) + 1;
        else return -1;
    }
    
};