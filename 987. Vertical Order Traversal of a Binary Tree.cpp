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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        map<int,map<int,multiset<int>>>mp; //col,row,nodes
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto [node,col_row]=q.front();
            q.pop();
            int col=col_row.first;
            int row=col_row.second;
            mp[col][row].insert(node->val);
            if(node->left) q.push({node->left,{col-1,row+1}});
            if(node->right) q.push({node->right,{col+1,row+1}}); 
        }
        for(auto it :mp){
            int col=it.first;
            auto rows=it.second;
            vector<int>temp;
            for(auto [row,nodes]:rows){
                temp.insert(temp.end(),nodes.begin(),nodes.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};