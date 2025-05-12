/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        for(char digit:num){
            while(!st.empty() && k>0 && st.top()>digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        //remove remaining digits from end if k>0
        while(k>0){
            st.pop();
            k--;
        }
        //build result string
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        } 
        reverse(res.begin(),res.end());
        // remove leading zeros
        int i=0;
        while(i<res.size() && res[i]=='0') i++;

        res = res.substr(i);
        return res.empty() ? "0" : res;
    }
};
