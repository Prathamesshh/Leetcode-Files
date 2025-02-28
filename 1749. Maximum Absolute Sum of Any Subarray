class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        for (int i : nums) {
            maxSum = max(0, maxSum + i);
            minSum = min(0, minSum + i);
        }
        return maxSum - minSum;
    }
};
