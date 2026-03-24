/*
Given a 0-indexed 2D integer matrix grid of size n * m, we define a 0-indexed 2D matrix p of size n * m as the product matrix of grid if the following condition is met:
Each element p[i][j] is calculated as the product of all elements in grid except for the element grid[i][j]. This product is then taken modulo 12345.
Return the product matrix of grid.


*/

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));

        long long suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = suffix;
                suffix = suffix * grid[i][j] % MOD;
            }
        }

        long long prefix = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = p[i][j] * prefix % MOD;
                prefix = prefix * grid[i][j] % MOD;
            }
        }

        return p;
    }
};
