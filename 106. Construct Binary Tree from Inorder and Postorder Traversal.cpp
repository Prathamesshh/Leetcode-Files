class Solution {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& postidx,
                     int start, int end, unordered_map<int, int>& inmap) {
        if (postidx < 0 || start > end)
            return nullptr;

        int rootVal = postorder[postidx--];
        TreeNode* root = new TreeNode(rootVal);
        int pos = inmap[rootVal];

        root->right = helper(inorder, postorder, postidx, pos + 1, end, inmap);
        root->left = helper(inorder, postorder, postidx, start, pos - 1, inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        int postidx = postorder.size() - 1;
        return helper(inorder, postorder, postidx, 0, inorder.size() - 1, inmap);
    }
};
