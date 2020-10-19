class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        
        unordered_map<string, int> Map;
        unordered_map<string, int> Bans;
        string Temp = "";
        
        for(int i=0; i<paragraph.length(); i++){
            if(paragraph[i] < 'a' || paragraph[i] > 'z'){
                if(Temp != ""){
                    Map[Temp]++;
                    Temp = "";
                }
            } else{
                Temp += paragraph[i];
            }
        }
        
        if(Temp != ""){
            Map[Temp]++;
        }
        
        for(int i=0; i<banned.size(); i++){
            Bans[banned[i]]++;
        }
        
        int Max = INT_MIN;
        string Sol = "";
        
        for(auto itr = Map.begin(); itr != Map.end(); itr++){
            if(itr->second > Max && Bans.find(itr->first) == Bans.end()){
                Max = itr->second;
                Sol = itr->first;
            }
        }
        
        return Sol;
    }
};