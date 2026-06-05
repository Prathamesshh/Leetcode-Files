/*
You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].
 

Example 1:

Input: num1 = 120, num2 = 130

Output: 3

Explanation:

In the range [120, 130]:

120: middle digit 2 is a peak, waviness = 1.
121: middle digit 2 is a peak, waviness = 1.
130: middle digit 3 is a peak, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 2:

Input: num1 = 198, num2 = 202

Output: 3

Explanation:

In the range [198, 202]:

198: middle digit 9 is a peak, waviness = 1.
201: middle digit 0 is a valley, waviness = 1.
202: middle digit 0 is a valley, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 3:

Input: num1 = 4848, num2 = 4848

Output: 2

Explanation:

Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

 

Constraints:

1 <= num1 <= num2 <= 1015​​​​​​​
*/

class Solution {
public:
    using ll = long long;

    string s;

    // shift range [-1..9] → [0..10]
    pair<ll,ll> dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    pair<ll,ll> solve(int pos, int prev, int prev2, bool tight, bool started) {
        if (pos == s.size()) {
            return {started ? 1 : 0, 0};
        }

        int p = prev + 1;
        int p2 = prev2 + 1;

        if (vis[pos][p][p2][tight][started])
            return dp[pos][p][p2][tight][started];

        vis[pos][p][p2][tight][started] = true;

        int limit = tight ? s[pos] - '0' : 9;

        ll totalCount = 0;
        ll totalWave = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);
            bool nstarted = started || (d != 0);

            int nprev = nstarted ? d : -1;
            int nprev2 = prev;

            auto [cnt, wave] = solve(pos + 1, nprev, nprev2, ntight, nstarted);

            ll add = 0;

            if (started && prev != -1 && prev2 != -1) {
                if ((prev2 < prev && prev > d) || (prev2 > prev && prev < d)) {
                    add = 1;
                }
            }

            totalCount += cnt;
            totalWave += wave + cnt * add;
        }

        return dp[pos][p][p2][tight][started] = {totalCount, totalWave};
    }

    ll calc(ll x) {
        s = to_string(x);
        memset(vis, 0, sizeof(vis));
        return solve(0, -1, -1, 1, 0).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};
