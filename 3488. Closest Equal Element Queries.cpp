/*
You are given a circular array nums and an array queries.

For each query i, you have to find the following:

The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.
Return an array answer of the same size as queries, where answer[i] represents the result for query i.

 

Example 1:

Input: nums = [1,3,1,4,1,3,2], queries = [0,3,5]

Output: [2,-1,3]

Explanation:

Query 0: The element at queries[0] = 0 is nums[0] = 1. The nearest index with the same value is 2, and the distance between them is 2.
Query 1: The element at queries[1] = 3 is nums[3] = 4. No other index contains 4, so the result is -1.
Query 2: The element at queries[2] = 5 is nums[5] = 3. The nearest index with the same value is 1, and the distance between them is 3 (following the circular path: 5 -> 6 -> 0 -> 1).
*/



class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> numsPos;
        for (int i = 0; i < n; i++) {
            numsPos[nums[i]].push_back(i);
        }
        for (auto& [_, pos] : numsPos) {
            int x = pos[0];
            pos.insert(pos.begin(), pos.back() - n);
            pos.push_back(x + n);
        }
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            int x = nums[queries[i]];
            if (numsPos[x].size() == 3) {
                queries[i] = -1;
                continue;
            }
            int pos =
                lower_bound(numsPos[x].begin(), numsPos[x].end(), queries[i]) -
                numsPos[x].begin();
            queries[i] = min(numsPos[x][pos + 1] - numsPos[x][pos],
                             numsPos[x][pos] - numsPos[x][pos - 1]);
        }
        return queries;
    }
};
