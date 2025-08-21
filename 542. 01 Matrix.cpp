class Solution {
public:
    void update(vector<vector<int>>mat,vector<vector<int>> &dis,int dr[],int dc[]){
        queue<pair<int,int>>q;
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dis[i][j]=0;
                    q.push({i,j});
                }
                else{
                    dis[i][j]=INT_MAX;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(dis[nr][nc]>dis[r][c]+1){
                        dis[nr][nc] = dis[r][c] +1;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dis(mat.size(), vector<int>(mat[0].size(), 0));
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        update(mat,dis,dr,dc);
        return dis;
    }
};