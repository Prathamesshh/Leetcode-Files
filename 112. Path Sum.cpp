/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int tsum;
    bool hasPathSum(TreeNode* root, int targetSum) {
        tsum = targetSum;
        return helper(root,0);

    }

    bool helper(TreeNode* root ,int sum) {
        if (root == nullptr) return false;
        if(!root->left && !root->right && sum+root->val == tsum) return true;
        return helper(root->left,sum+root->val) || helper(root->right,sum+root->val);
    }
};