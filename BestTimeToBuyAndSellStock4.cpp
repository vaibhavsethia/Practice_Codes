class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int N = prices.size();
        
        if(N <= 1 || k == 0){
            return 0;
        } else if(2 * k >= N){
            int MaxProfit = 0;
        
            for(int i=0; i<prices.size() - 1; i++){
                if(prices[i+1]>prices[i]){
                    MaxProfit += prices[i+1] - prices[i];
                }
            }

            return MaxProfit;
        } else{
            int DP[2 * k + 1];
            DP[0] = -1 * prices[0];
            
            for(int i = 1; i < 2*k; i++){
                if(i%2 == 1){
                    DP[i] = 0;
                } else{
                    DP[i] = INT_MIN;
                }
            }
            
            for(int i = 0; i < N; i++){
                for(int j = 0; j <= 2*k; j++){
                    if(j == 0){
                        DP[j] = max(DP[j], -1 * prices[i]);
                    } else if(j%2 == 0){
                        DP[j] = max(DP[j], DP[j-1] - prices[i]);
                    } else{
                        DP[j] = max(DP[j], DP[j-1] + prices[i]);
                    }
                }
            }
            
            return DP[2*k-1];
        }
    }
};