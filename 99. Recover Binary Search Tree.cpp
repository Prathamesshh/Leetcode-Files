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
   TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev && node->val < prev->val) {
            if (!first) first = prev;   
            second = node;              
        }
        prev = node;
        inorder(node->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);

        if(first && second) swap(first->val, second->val);
    }
};