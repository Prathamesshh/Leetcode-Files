/*
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int largestArea = 0;

        vector<int> heights(COLS);

        for(int i = 0 ; i < ROWS ; ++i)
        {
            for(int j = 0 ; j < COLS ; ++j)
            {
                if(matrix[i][j] == 0)
                    heights[j] = 0;
                else
                    heights[j] += 1;
            }

            vector<int> sorted = heights;
            sort(sorted.rbegin(), sorted.rend());

            for(int j = 0 ; j < COLS ; ++j)
            {
                largestArea = max(largestArea, sorted[j]*(j+1));
            }
        }

        return largestArea;
    }
};
