class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long total = 0;
        int positiveCount = 0;
        int minPositiveGain = INT_MAX;

        for (int num : nums) {
            int xorNum = num ^ k;
            int gain = xorNum - num;

            if (gain > 0) {
                total += xorNum;
                positiveCount++;
                minPositiveGain = min(minPositiveGain, gain);
            } else {
                total += num;
                minPositiveGain = min(minPositiveGain, -gain); // cost if we had switched it
            }
        }

        // If odd number of gains, remove the smallest gain to make it even
        if (positiveCount % 2 == 1) {
            total -= minPositiveGain;
        }

        return total;
    }
};
