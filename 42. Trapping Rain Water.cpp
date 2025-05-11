/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int l_max = 0, r_max = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= l_max)
                    l_max = height[left];
                else
                    water += l_max - height[left];
                ++left;
            } 
            else {
                if (height[right] >= r_max)
                    r_max = height[right];
                else
                    water += r_max - height[right];
                --right;
            }
        }

        return water;
    }
};
