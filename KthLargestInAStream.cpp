#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, Count = 0, Temp;
    priority_queue <int, vector<int>, greater<int> > Map;
    cin>>N>>K;

    for(int i=1; i<=N; i++){
        cin>>Temp;
        if(Count < K){
            Map.push(Temp);
            Count++;
            cout<<"-1"<<endl;
        } else if(Count == K){
            Map.push(Temp);
            cout<<Map.top()<<endl;
            Count++;
        } else{
            if(Temp <= Map.top()){
                cout<<Map.top()<<endl;
            } else{
                Map.pop();
                Map.push(Temp);
                cout<<Map.top()<<endl;
            }
            Count++;
        }
    }
}
