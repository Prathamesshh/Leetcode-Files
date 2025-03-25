class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;  // A single character is already a palindrome
        
        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome (single character center)
            expandAroundCenter(s, i, i, start, maxLen);
            // Even length palindrome (two character center)
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int newLen = right - left + 1;
            if (newLen > maxLen) {
                maxLen = newLen;
                start = left;
            }
            left--;
            right++;
        }
    }
};
