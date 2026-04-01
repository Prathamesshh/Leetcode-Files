/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
  */

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if(n == 1) return nums[0];

//         vector<int> dp(n,0);

//         dp[0] = nums[0];
//         dp[1] = max(nums[0],nums[1]);

//         for(int i=2;i<n;i++){
//             dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
//         }
//         return dp[n-1];
//     }
// };

/// space otimizied----------------->

class Solution {
public:
    int rob(vector<int>& nums) { 
        int n = nums.size();

        if(n == 1) return nums[0];

        int prev2 = nums[0];
        int prev = max(nums[0],nums[1]);
        int curr = INT_MIN;

        for(int i=2;i<n;i++){
            curr = max(prev,nums[i]+prev2);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

