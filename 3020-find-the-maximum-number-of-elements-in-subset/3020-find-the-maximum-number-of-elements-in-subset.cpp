class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 1;
        unordered_map<long long,int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(auto &pair : mp){
            long long x = pair.first;
            if(x == 1){
                int oneCount = mp[1];
                if(oneCount % 2 == 0){    
                    oneCount--;
                }
                ans = max(ans, oneCount);
                continue;
            }

            int currLen = 0;
            while(mp[x] >= 2 && mp.find(x * x) != mp.end()){
                currLen += 2;
                x = x * x;
            }
            if(mp.find(x) != mp.end()){
                currLen++;
            }
            ans = max(ans, currLen);
        }
        return ans;
    }
};