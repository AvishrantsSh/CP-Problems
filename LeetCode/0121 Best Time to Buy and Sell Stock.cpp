class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, cost = 0;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            cost = max(cost, prices[i] - minPrice);
        }
        return cost;
    }
};