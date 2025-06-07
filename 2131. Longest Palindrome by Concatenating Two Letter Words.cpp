/*
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.
*/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;
        for (string w : words) mpp[w]++;

        int count = 0, alreadyPalindrome = 0;
        for (auto& [w, freq] : mpp) {
            string s = w;
            reverse(s.begin(), s.end());
            if (w == s) {
                count += (freq / 2) * 4;
                if (freq % 2) alreadyPalindrome = 1;
            } else if (w < s && mpp.count(s)) {
                count += min(freq, mpp[s]) * 4;
            }
        }
        return count + alreadyPalindrome * 2;
    }
};
