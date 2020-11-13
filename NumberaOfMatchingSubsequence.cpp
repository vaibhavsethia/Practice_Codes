class Solution {
public:
    bool isSubsequence(string t, string s) {
        int j=0;
        
        for(int i=0;i<s.length();i++){
            if(t[j]==s[i]){
                j++;
            }
            if(j==t.length()){
                return true;
            }
        }
        
        return false;
    }
    
    int numMatchingSubseq(string S, vector<string>& words) {
        int Count = 0;
        unordered_map<string, int> Map;
        
        for(int i=0; i<words.size(); i++){
            Map[words[i]]++;
        }
        
        for(auto itr=Map.begin(); itr!=Map.end(); itr++){
            if(isSubsequence(itr->first, S)){
                Count += itr->second;
            }
              
        }
        
        return Count;
    }
};