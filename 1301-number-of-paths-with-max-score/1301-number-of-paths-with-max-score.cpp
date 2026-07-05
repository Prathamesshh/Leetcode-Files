using ll = long long;
const int mod = 1e9 + 7;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, {-mod,0}));
        dp[m-1][n-1] = {0, 1};

        for (int i = m-1; i >= 0; i--) {

            for (int j = n-1; j >= 0; j--) {

                if ((i == m-1 && j == n-1) || board[i][j] == 'X') {
                    continue;
                }

                ll ways = 0;
                int maxVal = max({dp[i][j+1][0], dp[i+1][j+1][0], dp[i+1][j][0]});

                ways = dp[i][j+1][0] == maxVal ? ways + dp[i][j+1][1] : ways;
                ways = dp[i+1][j+1][0] == maxVal ? ways + dp[i+1][j+1][1] : ways;
                ways = dp[i+1][j][0] == maxVal ? ways + dp[i+1][j][1] : ways;

                dp[i][j] = {maxVal + (board[i][j] - '0'), int(ways % mod)};
            }
        }

        dp[0][0][0] = dp[0][0][0] - ('E' - '0');

        return dp[0][0][0] < 0 ? vector<int>(2,0) : dp[0][0];
    }
};