int getFirstSetBitPos(int n)
{
    return ffs(n);
}

int getFirstSetBitPos(int n)
{
    int i=1;
    while(n>0){
      if(n%2 == 1){
        return i++;
      }
      n /= 2;
      i++;
    }
  return i; 
}