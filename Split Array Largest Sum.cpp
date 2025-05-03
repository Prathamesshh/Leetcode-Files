/*Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans=high;
     while (low <= high) {
        int mid = (low + high) / 2;
        int subarrys = findsum(nums, mid);
        if (subarrys <= k) {
            ans=mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
    }
   int findsum(vector<int> &nums, int sum) {
    int k = 1; 
    int additon = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (additon + nums[i] <= sum) {
            
            additon += nums[i];
        }
        else {
            k += 1; 
            additon = nums[i];
        }
    }
    return k;
}

};


