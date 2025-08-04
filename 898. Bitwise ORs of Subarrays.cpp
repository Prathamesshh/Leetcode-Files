class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> ans;
        unordered_set<int> cur;
        cur.insert(0);
        
        for (int x : A) {
            unordered_set<int> cur2;
            for (int y : cur) {
                cur2.insert(x | y);
            }
            cur2.insert(x);
            cur = cur2;
            
            for (int val : cur) {
                ans.insert(val);
            }
        }
        
        return ans.size();
    }
};
