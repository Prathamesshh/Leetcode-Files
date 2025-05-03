class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sub = 1 << nums.size();
        vector<vector<int>> output;
        
        for (int num = 0; num < sub; num++) {
            vector<int> subset;
            for (int i = 0; i < nums.size(); i++) {
                if (num & (1 << i)) 
                    subset.push_back(nums[i]);
            }
            output.push_back(subset);
        }
        return output;
    }
};



// class Solution {
// public:
//         vector<vector<int>> output;
//         int n;
//     void backtrack(int first,vector<int>curr,vector<int>nums){
//         //Add the current combination to output
//         output.push_back(curr);

//         for(int i=first;i<n;++i){
//             // Add the next element to the current combination
//             curr.push_back(nums[i]);
//             // Recurse to form the next combination
//             backtrack(i + 1, curr, nums);
//             // Backtrack and remove the last element
//             curr.pop_back();
//         }
//     }    



//     vector<vector<int>> subsets(vector<int>& nums) {
//         n = nums.size();
//         vector<int> curr;
//         backtrack(0,curr,nums); //generate all substrings
//         return output;
//     }
// };

