#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    
    while(T--){
        string S;
        cin>>S;
        
        unordered_map<char, int> Map1;
        unordered_map<char, int> Map2;
        
        for(int i=0; i<S.length(); i++){
            Map1[S[i]]++;
        }
        
        int Start = 0, StartIndex = -1, Minlen = INT_MAX;
        
        for(int i=0; i<S.length(); i++){
            Map2[S[i]]++;
            
            if(Map2.size() == Map1.size()){
                while(Map2[S[Start]] > 1){
                    if(Map2[S[Start]] > 1){
                        Map2[S[Start]]--;
                    }
                    Start++;
                }
                
                int LenWindow = i - Start + 1; 
                if (Minlen > LenWindow) { 
                    Minlen = LenWindow; 
                    StartIndex = Start; 
                } 
            }
        }
        
        cout<<Minlen<<endl;
    }
	return 0;
}