class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int a1 = INT_MIN, a2 = INT_MAX;
        for (auto [c, freq] : mp) {
            if (freq % 2)
                a1 = max(a1, freq);
            else
                a2 = min(a2, freq);
        }
        return a1 - a2;
    }
};