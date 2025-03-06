class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans(2);
        vector<int> freq(n*n+1,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(freq[grid[i][j]]==1) ans[0]=grid[i][j];

                else freq[grid[i][j]]=1;
            }
        }

        for(int i=1;i<=n*n;i++){
            if(freq[i]==0){
                ans[1]=i;
                break;
            }
        }
        return ans;
    }
};
