/*You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.
    */

class Solution {
public:
    string largestOddNumber(string num) {
        int right = num.length() - 1;
        while (right >= 0) {
            if (num[right] % 2 == 1) {  
                return num.substr(0, right + 1);
            }
            right--;
        }
        
        return ""; 
    }
};
