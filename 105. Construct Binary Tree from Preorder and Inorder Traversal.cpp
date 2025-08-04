class Solution {
private:
    TreeNode* Helper(vector<int>& pre, int& preIdx, int inStart, int inEnd,
                     unordered_map<int, int>& inMap) {
        if (preIdx >= pre.size() || inStart > inEnd)
            return nullptr;
            
        TreeNode* root = new TreeNode(pre[preIdx++]);

        int idx = inMap[root->val];
        root->left = Helper(pre, preIdx, inStart, idx - 1, inMap);
        root->right = Helper(pre, preIdx, idx + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        int preIdx = 0;
        return Helper(preorder, preIdx, 0, inorder.size() - 1, inMap);
    }
};