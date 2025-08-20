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
    bool search(TreeNode* root, int k, TreeNode* curr) {
        if (!root) return false;
        if (root->val == k && root != curr) return true;
        if (root->val < k)
            return search(root->right, k, curr);
        else
            return search(root->left, k, curr);
    }

    bool ans(TreeNode* root, int k, TreeNode* curr) {
        if (!curr) return false;
        if (search(root, k - curr->val, curr)) return true;
        return ans(root, k, curr->left) || ans(root, k, curr->right);
    }

    bool findTarget(TreeNode* root, int k) {
        return ans(root, k, root);
    }
};
