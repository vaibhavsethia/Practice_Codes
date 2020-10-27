int Solution::solve(vector<vector<int> > &A) {
    
     vector<pair<int,int>> Time;
    
    for(int i=0;i<A.size();i++){
        Time.push_back(make_pair(A[i][0],1));
        Time.push_back(make_pair(A[i][1],0));
    }
    
    sort(Time.begin(),Time.end());
    
    int Curr=0, Max=0;
    
    for(pair<int,int> x:Time){
        if(x.second==1){
            Curr++;
        }
        if(x.second==0){
            Curr--;
        }
        
        if(Max < Curr){
            Max = Curr;
        }
    }
    
    return Max;
    
}