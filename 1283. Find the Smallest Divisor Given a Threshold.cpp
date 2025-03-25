/*Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.
    */

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int k) {
        // Initialize binary search range
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (SmallestDivisor(nums, mid) <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int SmallestDivisor(vector<int>& nums, int div) {
        int sum = 0;
        for (int num : nums) {
            sum += ceil((double)num/(double)div);  
        }
        return sum;
    }
};
