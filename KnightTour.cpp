#include <bits/stdc++.h>
using namespace std;
#define N 8

int isSafe(int x, int y, int Sol[N][N]){
  return (x >= 0 && x < N && y >= 0 && y < N && Sol[x][y] == -1);
}

int KnightTourUtil(int x, int y, int Move, int Sol[N][N], int xMove[N], int yMove[N]){
  int k, NextX, NextY;
  if(Move == N * N){
      return 1;
  }
  for (k = 0; k < 8; k++){
    NextX = x + xMove[k];
    NextY = y + yMove[k];

    if (isSafe(NextX, NextY, Sol))
    {
      Sol[NextX][NextY] = Move;
      if (KnightTourUtil(NextX, NextY, Move + 1, Sol, xMove, yMove)){
          return 1;
      }
      else{
          Sol[NextX][NextY] = -1;
      }     
    }
  }

  return 0;
}

void Print(int Sol[N][N])
{
  for (int x = 0; x < N; x++){
    for (int y = 0; y < N; y++)
      cout <<" "<<Sol[x][y]<<" ";
    cout << endl;
  }
}

void KnightTour()
{
  int Sol[N][N];

  for (int x = 0; x < N; x++){
    for (int y = 0; y < N; y++){
      Sol[x][y] = -1;
    }
  }

  int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

  Sol[0][0] = 0;

  if (KnightTourUtil(0, 0, 1, Sol, xMove, yMove) == 0){
    cout <<"No Solution";
  }
  else{
    Print(Sol);
  }
}

int main()
{
  KnightTour();
  return 0;
}