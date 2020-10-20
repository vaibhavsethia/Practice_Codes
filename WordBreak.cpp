class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.length();
        int M = wordDict.size();
        
        if(M == 0){
            return N == 0;
        }
             
        vector<bool> DP (N+1, false);
        DP[N]=true;

        for(int i = N-1; i>=0; i--){
            for(int j=0; j<M; j++){
               int Len = wordDict[j].length();
                if(i+Len <= N){
                    if(s.substr(i,Len)==wordDict[j]){
                      DP[i] = DP[i+Len];
                      
                      if(DP[i]){
                        break;
                      }
                    }
                }
            }
        }
        return DP[0];
    }
};