class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        sort(begin(nums), end(nums));
        int l=0, r=0;
        while(r<nums.size()){
            while(nums[r]-nums[l] > 1){
                l++;
            }
            if(nums[r]-nums[l] == 1){
                ans = max(r-l+1, ans);
            }
            r++;
        }
        return ans;
    }
};