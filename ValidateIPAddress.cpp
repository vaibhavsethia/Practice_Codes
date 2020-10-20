class Solution {
public:
    static bool comp(string s, string t){
        if(s.size() > t.size()) return true;
        if(s.size() < t.size()) return false;
        return s > t;
    }
    
    string validIPAddress(string IP) {
        int Dot = 0, Colon = 0;
        for(int i=0; i<IP.size(); i++){
            if(IP[i] == '.'){
                Dot++;
            } else if(IP[i] == ':'){
                Colon++;
            }
        }
        
        if(Dot !=0 && Dot != 3){
            return "Neither";
        }
        if(Colon !=0 && Colon != 7){
            return "Neither";
        }
        
        if(Dot == 3){
            vector<string> V(4);
            int j = 0;
            
            for(int i = 0; i < IP.size(); i++){
                if(IP[i] == '.'){
                    j++;
                }else if(IP[i] < 48 || IP[i] > 57){
                    return "Neither";
                }
                if(IP[i] != '.'){
                    V[j].push_back(IP[i]);
                }
            }
            
            for(string s: V){
                if(s.size() < 1 || s.size() > 3){
                    return "Neither";
                }
                if(comp(s,"255")){
                    return "Neither";
                }
                if(s != "0" && s[0] == '0'){
                    return "Neither";
                }
            }
            
            return "IPv4";
        } else if(Colon == 7){
            vector<string> V(8);
            int j = 0;
            
            for(int i = 0; i < IP.size(); i++){
                if(IP[i] >= 97  && IP[i] <= 122){
                    IP[i]-=32;
                }
                if(IP[i] == ':'){
                    j++;
                } else if((IP[i] >= 48 && IP[i] <= 57) || (IP[i] >= 65 && IP[i] <= 70)){
                } else{
                    return "Neither";
                }
                if(IP[i] != ':'){
                    V[j].push_back(IP[i]);
                }
            }
            
            for(string t: V){
                if(t.size() < 1  || t.size() > 4){
                    return "Neither";
                }
            }
            return "IPv6";
            
        } else{
            return "Neither";
        }
    }
};