class Solution {
public:
    bool vis[205][205];
    int n,m;
    bool valid(int i, int j)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }
    void dfs(int r,int c,vector<vector<char>>&board){
        vis[r][c] = true;
        int dr[4] ={-1,0,1,0};
        int dc[4] ={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(valid(nr,nc) && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr,nc,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O' && (i==0 || j==0 || i==n-1 || j==m-1))
                    dfs(i,j,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};