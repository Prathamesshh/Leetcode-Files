/*
  Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
  */

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack <int> st;
        int res = INT_MIN;
        for ( int i = 0 ; i<= n ; i++){
            while(!st.empty() && (i == n || h[st.top()] >= h[i])){
                int height = h[st.top()];
                st.pop();
                int width;
                if (st.empty()){
                    width = i;
                }else {
                    width = i - st.top()-1;
                }
                res = max (res, height*width);
            }
            st.push(i);
        }
        return res;
    }
};
