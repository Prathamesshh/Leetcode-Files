/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
*/

class Solution {
public:
    vector<int> prevsmaller(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&& arr[st.top()]>arr[i])
               st.pop();
            
            if(st.empty()) pse[i]=-1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> nextsmaller(vector<int>& arr)
    {
        int n=arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    long long mod = (int) (1e9+7);
    vector<int> pse = prevsmaller(arr);
    vector<int> nse = nextsmaller(arr);
    for(int i=0;i<n;i++){
        int left = i - pse[i];
        int right = nse[i]-i;
        sum=(sum+(left*right*1ll*arr[i])%mod)%mod;
    }
        return sum;
    }
};
