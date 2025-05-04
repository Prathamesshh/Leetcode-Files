class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxprofit = 0;

        while(r < prices.size()){

            if(prices[r]>prices[l]){
                maxprofit = max(maxprofit , prices[r] - prices[l]); 
            }
            else{
                l = r;
            }
            r ++;
        }
        return maxprofit;
    }
};
