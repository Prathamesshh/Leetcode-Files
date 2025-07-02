class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int modVal = 1e9 + 7;
        vector<int> power(1e7, 1);
        for(int i=1; i<power.size(); i++){
            power[i] = (2 * power[i-1]) % modVal;
        }

        int count = 0;
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.size()-1;
        while(low <= high){
            if(nums[low] + nums[high] > target){
                high--;
            }else{
                int diff = (high - low);
                count = (count%modVal + power[diff]%modVal) % modVal;
                low++;
            }
        }
        return count;
    }
};