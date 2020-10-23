class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        if(s.size() == 0){
            return {{}};
        }
            
        unordered_map<string,vector<string>> Map;
        
        for(int i=0; i<s.size(); i++){
            string A = s[i];
            sort(A.begin(),A.end());
            
            if(Map.find(A) == Map.end()){
                Map.insert({A, {s[i]}});
            }
            else{
                Map[A].push_back(s[i]);
            }
        }
        
        vector<vector<string>> Sol;
        
        for(auto itr = Map.begin(); itr != Map.end(); itr++){
            Sol.push_back(itr->second);
        }
        
        return Sol;
    }
};