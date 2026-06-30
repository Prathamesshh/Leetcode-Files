class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        int left = 0, right = 0;
        map<char, int> freq;
        int total = 0;

        while (right < len) {
            char curr = s[right];
            freq[curr]++;

            while (checkAllChar(freq)) {
                total += len - right;

                char lchar = s[left];
                freq[lchar]--;
                left++;
            }
            right++;
        }
        return total;
    }

    bool checkAllChar(map<char, int>& freq) {
        return freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0;
    }
};
