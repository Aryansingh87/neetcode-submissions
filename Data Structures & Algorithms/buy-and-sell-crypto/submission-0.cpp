class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int currprofit = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>currprofit){
                maxprofit = max(maxprofit , prices[i]-currprofit);
            }
            currprofit = min(currprofit , prices[i]);
        }
        return maxprofit;
    }
};
