/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/


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
    void helper(TreeNode* root, int k, int &cnt, int &ksmall) {
        if (!root || cnt >= k) return;
        
        helper(root->left, k, cnt, ksmall);
        
        cnt++;
        if (cnt == k) {
            ksmall = root->val;
            return; 
        }
        
        helper(root->right, k, cnt, ksmall);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ksmall = -1; 
        helper(root, k, cnt, ksmall);
        return ksmall;
    }
};
