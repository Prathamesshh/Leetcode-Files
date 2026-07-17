class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxNum = *max_element(nums.begin(), nums.end());
        long long cnt[maxNum + 1];
        memset(cnt, 0, sizeof(cnt));
        for (const int num: nums)
            ++cnt[num];
        for (int num = 1; num <= maxNum; num++) {
            for (int i = num * 2; i <= maxNum; i += num)
                cnt[num] += cnt[i];
        }
        for (int num = 1; num <= maxNum; num++)
            cnt[num] = cnt[num] * (cnt[num] - 1) / 2;
        for (int num = maxNum - 1; num >= 1; num--) {
            for (int i = num * 2; i <= maxNum; i += num)
                cnt[num] -= cnt[i];
        }
        for (int num = 2; num <= maxNum; num++)
            cnt[num] += cnt[num - 1];
        
        // for (int i = 1; i <= maxNum; i++)
        //     cout << i << "," << cnt[i] << endl;

        vector<int> res;
        res.reserve(queries.size());
        for (long long query: queries) {
            ++query;
            int l = 1, r = maxNum;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (cnt[m] >= query) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            res.push_back(r);
        }
        return res;
    }
};