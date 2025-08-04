/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return{};

        queue<TreeNode*> q;
        string res;
        int val;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            val = node->val +1000;
            res.push_back(val & 0x7F);
            res.push_back((node->left != nullptr ? 64 : 0) | (node->right != nullptr ? 32 : 0) | (val >> 7));
            if (node->left != nullptr)
                q.emplace(node->left);
            if (node->right != nullptr)
                q.emplace(node->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return nullptr;

        queue<TreeNode**> q;
        TreeNode* result;
        TreeNode** handle;
        int size = data.size();
        int val;
        char c;

        q.emplace(&result);
        for (int pos = 0; pos < size; pos += 2)
        {
            handle = q.front(); q.pop();

            val = data[pos];
            c = data[pos + 1];
            val |= (int)(c & 31) << 7;
            val -= 1000;
            *handle = new TreeNode(val);

            if (c & 64)
                q.emplace(&((*handle)->left));
            if (c & 32)
                q.emplace(&((*handle)->right));
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));