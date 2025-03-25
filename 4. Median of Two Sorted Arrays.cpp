/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
    */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // int n = nums1.size();
        // int m = nums2.size();
        // vector<int>res;
        // for(int i=0;i<n;i++){
        //     res.push_back(nums1[i]);
        // }
        // for(int i=0;i<m;i++){
        //     res.push_back(nums2[i]);
        // }
        // sort(res.begin(),res.end());
        
        // int N =res.size();
        // int low =0; int high =N-1;
        // if(N%2==1){
        //     double mid = (low+high)/2;
        //     return res[mid];
        // }
        // else{
        //     double med = (low+high)/2;
        //     double median = (double) (res[med]+res[med+1])/2;
        //     return median;
        // }
        
        // return 0;



// optimised approach
        int n = nums1.size(), m = nums2.size();
    
    // Ensure nums1 is the smaller array
    if (n > m) return findMedianSortedArrays(nums2, nums1);

    int low = 0, high = n, left = (n + m + 1) / 2;

    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        // Set default values for partitioning
        int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < n) ? nums1[mid1] : INT_MAX;
        int r2 = (mid2 < m) ? nums2[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            // Found the correct partition
            if ((n + m) % 2 == 1) {
                return max(l1, l2);  // Odd case
            } else {
                return (max(l1, l2) + min(r1, r2)) / 2.0;  // Even case
            }
        } else if (l1 > r2) {
            high = mid1 - 1;  // Move left
        } else {
            low = mid1 + 1;   // Move right
        }
    }
        return 0;
    }
    
};
