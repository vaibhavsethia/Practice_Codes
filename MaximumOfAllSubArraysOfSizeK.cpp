#include <bits/stdc++.h>
using namespace std;

template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
  public:

      bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
       }
       else {
        return false;
       }
 }
};

int main() {
    int T;
    cin>>T;
    
    while(T--){
        int N, K, Temp;
        cin>>N>>K;
        
        vector<int> A(N);
        custom_priority_queue <int> Q;
        
        Temp = K;
        
        for(int i=0; i<N; i++){
            cin>>A[i];
        }
        for(int i=0; i<K; i++){
            Q.push(A[i]);
        }
        
        for(int i=K; i<N; i++){
            cout<<Q.top()<<" ";
            Q.remove(A[i-K]);
            Q.push(A[i]);
        }
        cout<<Q.top()<<" ";
        cout<<endl;
    }
	return 0;
}

/*

*/