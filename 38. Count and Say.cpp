class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        for(int i = 1; i < n; i++){
            curr = RLE(curr);
        }
        return curr;
    }

private:
    string RLE(string s) {
        int count = 0;
        char curr = s[0];
        string res = "";
        for (char c : s) {
            if (c == curr) {
                count++;
            } else {
                res += to_string(count) + curr;
                curr = c;
                count = 1;
            }
        }
        res += to_string(count) + curr;
        return res;
    }
};
