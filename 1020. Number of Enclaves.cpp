class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;

    bool valid(int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    void dfs(int r, int c, vector<vector<int>>& grid) {
        vis[r][c] = true;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (valid(nr, nc) && !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1 &&
                   (i == 0 || j == 0 || i == n-1 || j == m-1)) {
                    dfs(i, j, grid);
                }
            }
        }
        int enclaves = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};
