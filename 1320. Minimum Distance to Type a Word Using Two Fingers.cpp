/*
You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.

For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
Given the string word, return the minimum total distance to type such string using only two fingers.

The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.

Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

 

Example 1:

Input: word = "CAKE"
Output: 3
Explanation: Using two fingers, one optimal way to type "CAKE" is: 
Finger 1 on letter 'C' -> cost = 0 
Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
Finger 2 on letter 'K' -> cost = 0 
Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
Total distance = 3*/


class Solution {
public:
    int getDistance(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return abs(x1 - x2) + abs(y1 - y2);
        }

    int minimumDistance(string word) {
        int n = word.size();
        int dp[n][26][26];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
            fill(dp[i][j], dp[i][j] + 26, INT_MAX >> 1);
            }
        }
        for (int i = 0; i < 26; ++i) {
            dp[0][i][word[0] - 'A'] = dp[0][word[0] - 'A'][i] = 0;
        }

        for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = getDistance(prev, cur);
            for (int j = 0; j < 26; ++j) {
                dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][prev][j] + d);
                dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][prev] + d);
                if (prev == j) {
                    for (int k = 0; k < 26; ++k) {
                        int d0 = getDistance(k, cur);
                        dp[i][cur][j] =
                        min(dp[i][cur][j], dp[i - 1][k][j] + d0);
                        dp[i][j][cur] =
                        min(dp[i][j][cur], dp[i - 1][j][k] + d0);
                    }
                }
            }
        }

        int ans = INT_MAX >> 1;
        for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
        ans = min(ans, dp[n - 1][i][j]);
        }
        }
        return ans;
        }
    };
]
