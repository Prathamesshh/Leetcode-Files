class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> num_set(arr.begin(), arr.end());
        int maxLength = 0;
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = arr[i], b = arr[j];
                int length = 2;
                
                while (num_set.count(a + b)) {
                    int temp = a + b;
                    a = b;
                    b = temp;
                    length++;
                }
                
                maxLength = max(maxLength, length);
            }
        }
        
        return maxLength > 2 ? maxLength : 0;
    }
};
