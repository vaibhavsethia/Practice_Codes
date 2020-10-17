#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> Smaller; 
    priority_queue<int,vector<int>,greater<int> > Greater;

    int N, Temp;
    cin>>N;

    cin>>Temp;
    int Median = Temp;
    Smaller.push(Temp);
    cout<<Median<<endl;

    for(int i=1; i<N; i++){
        cin>>Temp;
        if(Smaller.size() < Greater.size()){
            if(Temp < Median){
                Greater.push(Smaller.top());
                Smaller.pop();
                Smaller.push(Temp);
            } else{
                Greater.push(Temp);
            }
            Median = (Smaller.top() + Greater.top())/2;
        } else if(Smaller.size() > Greater.size()){
            if(Temp < Median){
                Smaller.push(Temp);
            } else{
                Smaller.push(Greater.top());
                Greater.pop();
                Greater.push(Temp);
            }
        } else{
            if(Temp < Median){
                Smaller.push(Temp);
                Median = Smaller.top();
            } else{
                Greater.push(Temp);
                Median = Greater.top();
            }
            Median = (Smaller.top() + Greater.top())/2;
        }

        cout<<Median<<endl;
    }
}
