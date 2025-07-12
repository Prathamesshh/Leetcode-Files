class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int num : arr){
            mp[num]++;
        }
        int max1=0;
        for(auto &it : mp){
            if(it.first == it.second)
            max1=max(max1,it.first);
        }
        if(max1==0)
        return -1;

        return max1;
    }
};