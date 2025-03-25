/*you are given an array of integers nums. Return the length of the longest subarray of nums which is either 
strictly increasing or strictly decreasing.
    */

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxx=1,inc=1;
        int minn=1,dec=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]>nums[i-1]){
            dec=1;
            inc++;
        if(maxx<inc) maxx=inc;
    }
    if(nums[i]<nums[i-1]){
        inc=1;
        dec++;
    if(minn<dec) minn=dec;
}

    if(nums[i]==nums[i-1])
        {
            inc=1;
            dec=1;
        }
    }
    return max(minn,maxx);
    }
};
