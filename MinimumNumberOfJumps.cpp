#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--){
	    int N;
	    cin>>N;
	    
	    vector<int> A(N);
	    for(int i=0; i<N; i++){
	        cin>>A[i];
	    }
	    
	    vector<int> Jumps(N+1, INT_MAX);
	    
	    if(N == 0 || A[0] < 1){
	        return INT_MAX;
	    }
	    
	    Jumps[0] = 0;
	    
	    for(int i=1; i<N; i++){
	        for(int j=0; j<i; j++){
	            if(i <= j + A[j] && Jumps[j] != INT_MAX){
	                Jumps[i] = min(Jumps[i], Jumps[j]+1);
	            }
	        }
	    }
	    
	    cout<<Jumps[N-1]<<endl;
	    
	}
}