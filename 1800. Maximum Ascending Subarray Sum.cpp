/*Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.
*/
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maaxi = nums[0];
        for(int i=1;i<nums.size();i++){
               if(nums[i]>nums[i-1]){
                   sum +=nums[i]; 
               }
               else
               {
                sum = nums[i];
               }
               maaxi = max(sum,maaxi);
        }
        return maaxi;
    }
};
