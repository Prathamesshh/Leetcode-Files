/*
You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:
If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.
Since the answer may be very large, return it modulo 109 + 7.
  */
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        for (char ch : s) {
            ++cnt[ch - 'a'];
        }
        for (int round = 0; round < t; ++round) {
            vector<int> nxt(26);
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % mod;
            for (int i = 2; i < 26; ++i) {
                nxt[i] = cnt[i - 1];
            }
            cnt = move(nxt);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % mod;
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};
