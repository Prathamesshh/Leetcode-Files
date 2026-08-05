class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int first = 0;
        int second = 0;
        while (first < nums1.size() && second < nums2.size()) {
            if (nums1[first] < nums2[second]) {
                first++;
            } else if (nums1[first] > nums2[second]) {
                second++;
            } else {
                return nums1[first];
            }
        }
        return -1;
    }
};