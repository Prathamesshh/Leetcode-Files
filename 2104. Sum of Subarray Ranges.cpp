/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        long long answer=0;

        //find sum of all minimums
        for(int right=0;right<=n;right++){
            while(!st.empty() && (right==n || nums[st.top()] >= nums[right])){
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1: st.top();
                answer -= (long long)nums[mid]*(right-mid) * (mid-left);
            }
            st.push(right);
        }

        //Find sum of all maximums
        st.pop();
        for(int right=0;right<=n;right++){
            while(!st.empty() && (right==n || nums[st.top()] <= nums[right])){
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1: st.top();
                answer += (long long)nums[mid]*(right-mid) * (mid-left);
            }
            st.push(right);
        }
        return answer;
    }
};


/*
class Solution {
public:
    // Next Smaller element
    vector<int> nse(vector<int> & nums){
        int n = nums.size();
        vector<int> ans(n) ; 
        stack<int> st ; 
        for(int i = n-1 ; i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            ans[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        return ans ;
    }
    //next greater element 
    vector<int> nge(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st ;
        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans ;
    }
    //prev smaller element
    vector<int> psee(vector<int> & nums){
        int n = nums.size();
        vector<int> ans(n) ; 
        stack<int> st;
        for(int i = 0 ;i<n;i++){
            while(!st.empty() && nums[st.top()]> nums[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans ;
    }
    //prev greater element 
    vector<int> pgee(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n) ; 
        stack<int> st ; 
        for(int i = 0 ; i<n ;i++){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans ;
    }
    long long sumM(vector<int> & nums){
        vector<int> NSE = nse(nums);
        vector<int> PSEE = psee(nums);
        long long  total = 0 ; 
        for(int i = 0 ; i<nums.size();i++){
            long long  left = i-PSEE[i];
            long long  right = NSE[i]-i;
            total += 1ll+right*left*(long long ) nums[i];
        }
        return total;
    }

    long long sumMAX(vector<int> & nums){
        vector<int> NGE = nge(nums);
        vector<int> PGEE = pgee(nums);
        long long  total = 0; 
        for(int i = 0 ; i<nums.size();i++){
            long long  left = i-PGEE[i];
            long long  right = NGE[i]-i;
            total += 1ll+right*left*(long long)nums[i];
        }
        return total ;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumMAX(nums)-sumM(nums);
    }
};
*/
