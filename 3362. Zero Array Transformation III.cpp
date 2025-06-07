/*
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most 1.
The amount by which the value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.
*/

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        priority_queue<int> heap;
        vector<int> deltaArray(nums.size() + 1, 0);
        int operations = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            operations += deltaArray[i];
            while (j < queries.size() && queries[j][0] == i) {
                heap.push(queries[j][1]);
                ++j;
            }
            while (operations < nums[i] && !heap.empty() && heap.top() >= i) {
                operations += 1;
                deltaArray[heap.top() + 1] -= 1;
                heap.pop();
            }
            if (operations < nums[i]) {
                return -1;
            }
        }
        return heap.size();
    }
};
