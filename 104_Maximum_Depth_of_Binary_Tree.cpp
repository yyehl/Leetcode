// 二叉树的最大深度

// 递归算法
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
    int maxDepth(TreeNode* root) {
        if (root == NULL)   return 0;
        else 
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// 非递归算法
class Solution１ {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)   return 0;
        queue<TreeNode*> qt;
        qt.push(root);
        int count = 0, len;
        while (!qt.empty())
        {
            len = qt.size();
            count++;
            while (len--)
            {
                if (qt.front()->left != NULL)   qt.push(qt.front()->left);
                if (qt.front()->right != NULL)  qt.push(qt.front()->right);
                qt.pop();
            }
        }
        return count;
        
    }
};

