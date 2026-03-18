/*
You are given a 0-indexed integer matrix grid and an integer k.
Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.
  */
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> cols(m);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int rows = 0;
            for (int j = 0; j < m; j++) {
                cols[j] += grid[i][j];
                rows += cols[j];
                if (rows <= k) {
                    res++;
                }
            }
        }
        return res;
    }
};
