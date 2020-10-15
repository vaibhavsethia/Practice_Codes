#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--){
	    int N;
	    cin>>N;
	    
	    vector<vector<int>> A(N, vector<int>(N));
	    for(int i=0; i<N; i++){
	        for(int j=0; j<N; j++){
	            cin>>A[i][j];
	        }
	    }
	    
	    for(int i=0; i<N; i++){
	        for(int j=0; j<N; j++){
	            if(j<i){
	                int Temp = A[i][j];
	                A[i][j] = A[j][i];
	                A[j][i] = Temp;
	            }
	        }
	    }
	    
	    for(int i=0; i<N/2; i++){
	        for(int j=0; j<N; j++){
	            int Temp = A[i][j];
                A[i][j] = A[N-i-1][j];
                A[N-i-1][j] = Temp;
	        }
	    }
	    
	    for(int i=0; i<N; i++){
	        for(int j=0; j<N; j++){
	            cout<<A[i][j]<<" ";
	        }
	    }
	    
	    
	}
	return 0;
}