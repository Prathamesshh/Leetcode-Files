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
    int depth=0;

    void findDepth(TreeNode *root,int level){
        if(root==NULL) return; 
        
        ++level;
        if(root->left) 
           findDepth(root->left,level);

        depth = max(depth,level);

        if(root->right)
           findDepth(root->right,level);
        
        --level;
    }
    int maxDepth(TreeNode* root) {
        int dp=0;
        findDepth(root,dp);
        return depth;
    }
};