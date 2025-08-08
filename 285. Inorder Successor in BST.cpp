/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
        TreeNode* findPredecessor(TreeNode* node) {
            node = node->left;
            while (node && node->right)
                node = node->right;
            return node;
        }

        TreeNode* findSuccessor(TreeNode* node) {
            node = node->right;
            while (node && node->left)
                node = node->left;
            return node;
        }

        void helper(vector<int>& res, TreeNode* root, int i, TreeNode*& pred, TreeNode*& succ){
            if (!root) return;

            if (i == root->data) {
                if (root->left)
                    pred = findPredecessor(root);
                if (root->right)
                    succ = findSuccessor(root);
            } 
            else if (i < root->data) {
                succ = root;
                helper(res, root->left, i, pred, succ);
            } 
            else {
                pred = root;
                helper(res, root->right, i, pred, succ);
            }
        }

		vector<int> succPredBST(TreeNode* root, int key){
			vector<int> res(2);
            TreeNode* pred = nullptr;
            TreeNode* succ = nullptr;

            helper(res, root, key, pred, succ);

            res[0] = pred ? pred->data : -1;
            res[1] = succ ? succ->data : -1;

            return res;
		}
};


