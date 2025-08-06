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
    int MinVal(TreeNode* root)
    {
        TreeNode* temp = root;
        while(temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp->val;
    }
    int MaxVal(TreeNode* root)
    {
        TreeNode* temp = root;
        while(temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return  nullptr;
        if(root->val==key){
            if(root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            if(root->left != nullptr && root->right == nullptr)
            {
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            if(root->left == nullptr && root->right != nullptr)
            {
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }   
            if(root->left != nullptr && root->right != nullptr)
            {
                int max = MaxVal(root->left);
                root->val = max;
                root->left = deleteNode(root->left,max);
                return root;
            } 
        }
        if(root->val > key)
        {
            root->left =  deleteNode(root->left, key);
            return root;
        }
        else
        {
            root->right = deleteNode(root->right,key);
            return root;
        }
    }
};