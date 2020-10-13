#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--){
	    int N;
	    cin>>N;
	    
	    priority_queue <int, vector<int>, greater<int> > Q;
	    
	    for(int i=0; i<N; i++){
	        int Temp; 
	        cin>>Temp;
	        Q.push(Temp);
	    }
	    
	    int Len = 0, Cost = 0;
	    
	    for(int i=0; i<N-1; i++){
	        int Num1 = Q.top();
	        Q.pop();
	        int Num2 = Q.top();
	        Q.pop();
	        
	        Len = Num1 + Num2;
	        Cost += Len;
	        
	        Q.push(Len);
	    }
	    
	    cout<<Cost<<endl;
	}
	return 0;
}