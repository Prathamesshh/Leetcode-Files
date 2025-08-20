class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int originalcolor = image[sr][sc];

        if(originalcolor == color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            image[r][c] = color;
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i]; 

                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==originalcolor) q.push({nr,nc});
            }
        }
        return image;
    }
};