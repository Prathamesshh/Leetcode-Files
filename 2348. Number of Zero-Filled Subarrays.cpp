class Solution {
public:
      long long f(int n) {
        return (1LL * n * (n + 1)) / 2; // avoid overflow
    }
    long long zeroFilledSubarray(vector<int>& nums) {

        vector<int> zeros;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cnt++;
            } else {

                if (cnt > 0) {
                    zeros.push_back(cnt);
                    cnt = 0;
                }
            }
        }
        if (cnt > 0)
            zeros.push_back(cnt);

        long long ans = 0;
        for (auto it : zeros) {

            long long  val = f(it);
            ans += val;
        }

        return ans;
    }
};