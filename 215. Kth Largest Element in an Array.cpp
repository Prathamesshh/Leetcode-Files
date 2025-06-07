class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minn = *min_element(nums.begin(),nums.end());
        int maxx = *max_element(nums.begin(),nums.end());

        vector<int> numbers(maxx-minn+1,0);

        for(int num:nums){
            numbers[num-minn]++;
        }
        int remain = k;

        for(int i=numbers.size()-1;i>=0;i--){
            remain -= numbers[i]; 
            if(remain<=0){
                return i+minn;
            }
        }
      return -1;
    }
};
