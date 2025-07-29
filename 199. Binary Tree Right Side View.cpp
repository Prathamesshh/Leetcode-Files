/**
 * Definition for a binary tree root.
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
    vector<int>ans;
    void helper(TreeNode* root,int lvl){
        if(root==nullptr) return;

        if(ans.size()==lvl) ans.push_back(root->val);

        if(root->right) helper(root->right,lvl+1);
        if(root->left) helper(root->left,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        helper(root,0);
        return ans;
    }
};