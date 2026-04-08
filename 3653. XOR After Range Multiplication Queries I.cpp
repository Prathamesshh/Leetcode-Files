/*
You are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [li, ri, ki, vi].

For each query, you must apply the following operations in order:

Set idx = li.
While idx <= ri:
Update: nums[idx] = (nums[idx] * vi) % (109 + 7)
Set idx += ki.
Return the bitwise XOR of all elements in nums after processing all queries.
  */


class Solution {
public:
    const int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &it : queries){
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];

            int idx = l;

            while(idx <= r){
                nums[idx] = (1LL * nums[idx] * v) % mod;
                idx += k;
            }
        }

        int xorr = 0;

        for(auto &it : nums){
            xorr ^= it;
        }

        return xorr;
    }
};
