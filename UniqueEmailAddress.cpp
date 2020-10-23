class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, vector<string>> Map;
            
        for(int i=0; i<emails.size(); i++){
            string Local = emails[i].substr(0, emails[i].find('@'));
            Local = Local.substr(0, emails[i].find('+'));
            Local.erase(remove(Local.begin(), Local.end(), '.'), Local.end());
            
            string Domain = emails[i].substr(emails[i].find('@')+1);
            
            auto itr = Map.find(Local);
            if(itr == Map.end()){
                Map.insert({Local, {Domain}});
            } else{
                if(find(itr->second.begin(), itr->second.end(), Domain) == itr->second.end()){
                    itr->second.push_back(Domain);
                }
            }
        }
        
        int Count = 0;
            for(auto itr = Map.begin(); itr != Map.end(); itr++){
                Count += itr->second.size();
            }
        
        return Count;
    }
};