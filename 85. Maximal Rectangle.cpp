/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
  */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int i,largestArea=0,nse,pse,element;
        stack<int> st;
        for(i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                nse=i;
                element=st.top();
                st.pop();
                if(st.empty()) pse=-1;
                else pse=st.top();
                largestArea=max(largestArea,(heights[element]*(nse-pse-1)));
            }
            st.push(i);
        }

        while(!st.empty())
        {
            nse=n;
            element=st.top();
            st.pop();
            if(st.empty()) pse=-1;
            else pse=st.top();
            largestArea=max(largestArea,(heights[element]*(nse-pse-1)));
        }
        return largestArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i,j;
        vector<vector<int>> newMatrix(n,vector<int> (m,0));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i>0)
                {
                    if(matrix[i][j]=='1')
                    {
                        int val=newMatrix[i-1][j];
                        newMatrix[i][j]=val+1;
                    }
                }
                else newMatrix[i][j]=matrix[i][j]-'0';
            }
        }
        int largestArea=0;
        for(i=0;i<n;i++)
        { 
            largestArea=max(largestArea,largestRectangleArea(newMatrix[i]));
        }
        return largestArea;
    }
};
