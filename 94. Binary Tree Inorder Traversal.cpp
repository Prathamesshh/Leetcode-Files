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
    void Inorder(TreeNode* root, vector<int> &answer){
        if(root==NULL) return;
        Inorder(root->left,answer);
        answer.push_back(root->val);
        Inorder(root->right,answer);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        Inorder(root,answer);
        return answer;

    }
};