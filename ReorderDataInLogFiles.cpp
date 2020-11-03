class Solution {
public:
    static bool Comp(pair<string, string> A, pair<string, string> B){
        return lexicographical_compare(A.second.begin(), A.second.end(), B.second.begin(), B.second.end());
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        queue<string> Q;
        vector<pair<string, string>> V;
        
        for(int i=0; i<logs.size(); i++){
            if(logs[i][0] == 'd'){
                Q.push(logs[i]);
            } else{
                V.push_back({logs[i].substr(0,4), logs[i].substr(5, logs[i].length()-1)});
            }
        }
        
        sort(V.begin(), V.end(), Comp);
        
        vector<string> Sol;
        
        for(auto itr = V.begin(); itr!= V.end(); itr++){
            Sol.push_back(itr->first+" "+itr->second);
        }
        
        while(!Q.empty()){
            Sol.push_back(Q.front());
            Q.pop();
        }
        
        return Sol;
    }
};