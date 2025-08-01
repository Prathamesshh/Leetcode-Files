/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int q;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : q(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParents(TreeNode* root, TreeNode* target,unordered_map<TreeNode*, TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root,target,parent_track);

        unordered_map<TreeNode* , bool>visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int dist=0;
        while(!q.empty()){
            int sz = q.size();
            if(dist++ == k) break;
            for(int i=0;i<sz;i++){
               TreeNode* curr = q.front(); q.pop();
               if(curr->left && !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left]=true;
               }
               if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right]=true;
               }
               if(parent_track[curr] && !visited[parent_track[curr]]){
                q.push(parent_track[curr]);
                visited[parent_track[curr]]=true;
               }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            res.push_back(curr->val);
        }
        return res;

    }
};




