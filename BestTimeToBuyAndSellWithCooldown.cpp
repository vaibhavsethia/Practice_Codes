class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1){
            return 0;
        }
        
        int N = prices.size();
        
        vector<int> NoStock(N, 0);
        vector<int> InHand(N, -1 * prices[0]);
        vector<int> Sold(N, 0);
        
        for(int i=1; i<N; i++){
            NoStock[i] = max(NoStock[i-1], Sold[i-1]);
            InHand[i] = max(InHand[i-1], NoStock[i-1] - prices[i]);
            Sold[i] = InHand[i-1] + prices[i];
        }
        
        return max(NoStock[N-1], Sold[N-1]);
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.size() <= 1){
//             return 0;
//         }

//         int N = prices.size();

//         int Buy = INT_MIN, Sell = INT_MIN, Reset = 0, PrevSell;
        
//         for(int i=1; i<N; i++){
//         {
//             PrevSell = Sell;
//             Sell = Buy + prices[i];
//             Buy = max(Buy,Reset-prices[i]);
//             Reset = max(Reset,PrevSell);
//         }
        
//         return max(Sell,Reset);
//     }
// };