class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int, int> mp;

        int i = 0;
        int j = 0;

        int ans = INT_MIN;
        while(j < n) {
            mp[fruits[j]]++;

            if(mp.size() <= 2) {
                ans = max(ans, j-i+1);
            }
            else { 
                mp[fruits[i]]--;

                if(mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }

                i++;
            }

            j++;
        }

        return ans;
    }
};