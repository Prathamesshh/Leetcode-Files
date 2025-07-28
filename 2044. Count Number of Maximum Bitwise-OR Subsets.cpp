class Solution {
public:
    int countSubsets(vector<int>nums,int index,int curror,int targetor){
        if(index == nums.size())
            return (curror == targetor)? 1:0;

        // Don't include the current number
        int countWithout = countSubsets(nums,index+1,curror,targetor);
        // Include the current number
        int countWith = countSubsets(nums,index+1,curror|nums[index],targetor);

        return countWithout + countWith;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxorval =0;
        for(int num:nums){
            maxorval |=num;
        }
        return countSubsets(nums,0,0,maxorval);
    }
};