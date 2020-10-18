class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int Cash = 0, Hold = -1 * prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            Cash = max(Cash, Hold + prices[i] - fee);
            Hold = max(Hold, Cash - prices[i]);
        }

        return Cash;
    }
};