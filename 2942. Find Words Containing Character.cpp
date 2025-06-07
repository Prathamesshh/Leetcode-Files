/*
You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order.
*/
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        for(int i = 0; i<words.size(); i++){
            for(int j = 0; j<words[i].size(); j++){
                if(words[i][j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
