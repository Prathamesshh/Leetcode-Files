class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int n = nums.size();
        int lastMin = -1, lastMax = -1, lastInvalid = -1;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK)
                lastInvalid = i;

            if (nums[i] == minK)
                lastMin = i;
            if (nums[i] == maxK)
                lastMax = i;
            
            int validStart = min(lastMin, lastMax);
            if (validStart > lastInvalid)
                res += validStart - lastInvalid;
        }
        
        return res;
    }
};
