class Solution {
public:
    int longestPalindromeSubseq(string s) {
        bool DP[s.length()][s.length()];
        memset(DP, false, sizeof(DP));
        
        int MaxLen = 1, Start = 0;
        
        for(int i=0; i<s.length(); i++){
            DP[i][i] = true;
        }
        
        for(int i=0; i<s.length()-1; i++){
           if(s[i] == s[i+1]){
               DP[i][i+1] = true;
               Start = i;
               MaxLen = 2;
           }
        }
        
        for(int i=3; i<=s.length(); i++){
            for(int j=0; j<s.length()-i+1; j++){
                int k = j + i - 1;
                
                if(DP[j+1][k-1] && s[j]==s[k]){
                    DP[j][k] == true;
                    
                    if(i > MaxLen){
                        Start = j;
                        MaxLen = i;
                    }
                }
            }
        }
        
        return MaxLen;
    }
};