class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0;
        for(auto & i : prices){
            buy = min(buy,i);
            profit = max(profit,i-buy);
        }
        return profit;
    }
};