class Solution {
public:
    bool isSubsequence(string t, string s) {
        int j=0;
        
        for(int i=0;i<s.length();i++){
            if(t[j]==s[i]){
                j++;
            }
        }
        
        return j==t.length();
    }
};