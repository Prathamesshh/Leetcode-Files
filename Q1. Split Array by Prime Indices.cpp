class Solution {
public:
    bool numIsPrime(long long n){
        if(n==0||n==1) return false;
        int i=2;
        while(i<=sqrt(n)){
            if(n%i==0) return false;
            i++;
        }
        return true;
    }
    
    long long splitArray(vector<int>& nums) {
        long long sum =0;
        int n = nums.size();
        for(int j=0;j<=n-1;j++){
            if(numIsPrime(j)) sum += nums[j];
            else 
                sum = sum-nums[j];
        }
        if(sum<0) sum*=(-1);

    return sum;
    }
}