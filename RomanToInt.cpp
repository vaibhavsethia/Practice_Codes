#include <bits/stdc++.h>
using namespace std;

int main() {
    int number[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string symbol[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

    string S;
    cin>>S;

    int Sol = 0;

    while(S.length()){
        int i = 0;
        for(; i<13; i++){
            if(symbol[i].length() == 2){
                if(S[S.length()-1] == symbol[i][1] && S[S.length()-2] == symbol[i][0]){
                    S.pop_back();
                    S.pop_back();
                    break;
                }
            } else{
                if(S[S.length()-1] == symbol[i][0]){
                    S.pop_back();
                    break;
                }
            }
        }

        int Val = number[i];
        Sol += Val;
    }

    cout<<Sol<<endl;
}
