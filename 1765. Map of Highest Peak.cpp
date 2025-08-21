#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void update(vector<vector<int>>& isWater, vector<vector<int>>& dis, int dr[], int dc[]) {
        queue<pair<int,int>> q;
        int n = isWater.size();
        int m = isWater[0].size();

        // Initialize heights
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {  // water cells
                    dis[i][j] = 0;
                    q.push({i, j});
                } else {
                    dis[i][j] = INT_MAX; // land starts unassigned
                }
            }
        }

        // BFS expansion
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if(dis[nr][nc] > dis[r][c] + 1) {
                        dis[nr][nc] = dis[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> dis(isWater.size(), vector<int>(isWater[0].size(), 0));
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        update(isWater, dis, dr, dc);
        return dis;
    }
};
