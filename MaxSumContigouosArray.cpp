int Solution::maxSubArray(const vector<int> &A) {
    int Max = 0, Curr = 0; 
    
   for (int i = 0; i < A.size(); i++) { 
       Curr = Curr + A[i]; 
       
       if (Curr < 0){
           Curr = 0; 
       } else if (Max < Curr){
           Max = Curr; 
       }
   } 
   return Max; 
}
