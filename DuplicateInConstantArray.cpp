int Solution::repeatedNumber(const vector<int> &A) {
    unordered_set<int> S;
    
    for(int i=0; i<A.size(); i++){
        if(S.find(A[i]) != S.end()){
            return A[i];
        } else{
            S.insert(A[i]);
        }
    }
    
    return -1;
}
