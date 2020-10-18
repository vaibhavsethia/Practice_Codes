class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        
        if(N <= 1){
            return 0;
        } else{
            int DP[5];
            DP[0] = -1 * prices[0];
            
            for(int i = 1; i < 4; i++){
                if(i%2 == 1){
                    DP[i] = 0;
                } else{
                    DP[i] = INT_MIN;
                }
            }
            
            for(int i = 0; i < N; i++){
                for(int j = 0; j <= 4; j++){
                    if(j == 0){
                        DP[j] = max(DP[j], -1 * prices[i]);
                    } else if(j%2 == 0){
                        DP[j] = max(DP[j], DP[j-1] - prices[i]);
                    } else{
                        DP[j] = max(DP[j], DP[j-1] + prices[i]);
                    }
                }
            }
            
            return DP[3];
        }
    }
};

