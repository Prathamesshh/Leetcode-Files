/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
  */

class Solution {
public:
    static int maxNumberOfBalloons(string& text) {
        int freq[26]={0};
        for(char c : text){
            freq[c-'a']++;
        }
        return min({freq[0], freq[1], freq['l'-'a']>>1, freq['o'-'a']>>1, freq['n'-'a']});
    }
};
