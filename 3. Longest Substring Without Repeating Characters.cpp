class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxlen = 0;
        unordered_set<char> mpp;

        for (int right = 0; right < s.length(); right++) {
            while (mpp.find(s[right]) != mpp.end()) {
                mpp.erase(s[left]);
                left++;
            }

            mpp.insert(s[right]);
            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;        
    }
};
