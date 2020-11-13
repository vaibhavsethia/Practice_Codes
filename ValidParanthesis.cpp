class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                S.push(s[i]);
            } else{
                if(s[i] == ')'){
                    if(S.empty()){
                        return false;
                    } else{
                        if(S.top() != '('){
                            return false;
                        } else{
                            S.pop();
                        }
                    }
                } else if(s[i] == '}'){
                    if(S.empty()){
                        return false;
                    } else{
                        if(S.top() != '{'){
                            return false;
                        } else{
                            S.pop();
                        }
                    }
                } else{
                    if(S.empty()){
                        return false;
                    } else{
                        if(S.top() != '['){
                            return false;
                        } else{
                            S.pop();
                        }
                    }
                }
            }
        }
        
        if(S.empty() == true){
            return true;
        }
        
        return false;
    }
};