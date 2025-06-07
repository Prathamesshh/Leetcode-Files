class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size()*board.size();
        vector<vector<int>> newboard(board.size());
        for(int i=board.size()-1;i>=0;i--){
            if(i%2==board.size()%2){
                reverse(board[i].begin(),board[i].end());
            }
            newboard[board.size()-i-1]=board[i];
        }
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            for(int j=0;j<sz;j++){
                int index=q.front();
                if(index==n-1) return ans;
                q.pop();
                for(int i=index+1;i<=min(n-1,index+6);i++){
                    if(vis[i]) continue;
                    vis[i]=1;
                    int row=i/(board.size());
                    int col=i%(board.size());
                    if(newboard[row][col]!=-1){
                        q.push(newboard[row][col]-1);
                    }
                    else{
                        q.push(i);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
