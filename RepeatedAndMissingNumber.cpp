vector<int> repeatedNumber(const vector<int> &V)
{
  int Sum = 0;
  int Squares = 0;
  int Temp;

  for (int i = 0; i < V.size(); i++)
  {
    Temp = V[i];
    Sum += Temp;
    Sum -= (i + 1);
    Squares += (Temp * Temp);
    Squares -= (i + 1) * (i + 1);
  }
  Squares /= Sum;

  int A = ((Sum + Squares) / 2);
  int B = Squares - A;

  vector<int> Sol;

  ret.push_back(A);
  ret.push_back(B);
  return ret;
}