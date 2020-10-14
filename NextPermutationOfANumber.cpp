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
	    
	    int i = N-1;
	    for(;i>0; i--){
	        if(A[i]>A[i-1]){
	            break;
	        }
	    }
	    
	    int dig1 = A[i-1], small = i;
	    for(int j=i+1; j<N; j++){
	        if(A[j] > dig1 && A[j] < A[small]){
	            small = j;
	        }
	    }
	    
	    int T = A[small];
	    A[small] = A[i-1];
	    A[i-1] = T;
	    
	    sort(A.begin()+i, A.end());
	    
	    for(int i=0; i<N; i++){
	        cout<<A[i]<<" ";
	    }
	    cout<<endl;
	}
}