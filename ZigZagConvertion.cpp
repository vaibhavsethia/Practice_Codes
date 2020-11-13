class Solution {
public:
    string convert(string s, int numRows) {
        string Sol;
        vector <string> Row(numRows);

        int i=0;

        while(i<s.size()){                                      
            for(int j=0;j<numRows && i<s.size(); j++, i++){
              Row[j] += s[i];
            }
            for(int j=numRows - 2;j>0 && i<s.size(); j--, i++){
              Row[j] += s[i];
            }
        }

        for(int j=0;j<numRows; j++){
          Sol += Row[j];
        }

        return Sol;
        Row.clear()
    }
};