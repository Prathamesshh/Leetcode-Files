class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i = 0 ;i<n ; i++){
            int num = nums[i];
            int moreneeded = target - num;
            if(mpp.find(moreneeded)!= mpp.end()){
                return{mpp[moreneeded],i};
            }
            mpp[num]=i;
        }
        return{-1,-1};
    
    }
};
