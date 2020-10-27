int Solution::maxArr(vector<int> &A)
{
  int Sum = INT_MIN, Max1 = INT_MIN, Max2 = INT_MIN, Min1 = INT_MAX, Min2 = INT_MAX;
  
  for (auto i = 0; i < A.size(); ++i){
    Max1 = max(Max1, A[i] + i);
    Max2 = max(Max2, A[i] - i);
    Min1 = min(Min1, A[i] + i);
    min2 = min(min2, A[i] - i);
  }
  
  Sum = max(Max1 - Min1, Max2 - min2);
  return Sum;
}