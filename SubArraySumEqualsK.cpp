class Solution {
public:
    int subarraySum(vector<int>& arr, int k){
        unordered_map<int, int> Map; 
    
        int Sum = 0, Ans = 0;
        Map[0] = 1;  
        
        for(int i = 0; i < arr.size(); i ++){
            Sum += arr [ i ] ; 
    
            if (Map.find(Sum-k) != Map.end()){
                Ans += Map[Sum-k]; 
            }
            
            Map[Sum]++;
        }
    
        return Ans;     
    }
};