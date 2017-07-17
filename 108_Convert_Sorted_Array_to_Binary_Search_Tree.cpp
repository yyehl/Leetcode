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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_tree(nums, 0, nums.size()-1);
    }
    TreeNode* build_tree(const vector<int>& nums, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            TreeNode* ptr = new TreeNode(nums[mid]);
            ptr->left = build_tree(nums, left, mid-1);
            ptr->right = build_tree(nums, mid+1, right);
            return ptr;
        }
        else if (left == right)
        {
            TreeNode* ptr = new TreeNode(nums[left]);
            return ptr;
        }
        else   // left > right
            return NULL;    
    }
};