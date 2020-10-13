#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--){
	    int N;
	    cin>>N;
	    
	    vector<char> S(N);
	    
	    for(int i=0; i<N; i++){
	        cin>>S[i];
	    }
	    
	    queue<char> Q; 
        int charCount[26] = { 0 }; 
      
        for (int i = 0; S[i]; i++) { 
            Q.push(S[i]); 
            charCount[S[i] - 'a']++; 
      
            while (!Q.empty()) { 
                if (charCount[Q.front() - 'a'] > 1) 
                    Q.pop(); 
                else { 
                    cout << Q.front() << " "; 
                    break; 
                } 
            } 
      
            if (Q.empty()) 
                cout << -1 << " "; 
        } 
        cout << endl; 
    }
}