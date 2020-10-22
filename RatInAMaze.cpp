#include<bits/stdc++.h>
using namespace std;

void Print(vector<vector<int>> Sol){
  for (int i = 0; i < Sol.size(); i++){
    for (int j = 0; j < Sol.size(); j++){
      cout<<" "<<Sol[i][j]<<" ";
    }
    cout<<endl;
  }
}

bool isSafe(vector<vector<int>> Maze, int x, int y){
  return (x >= 0 && x < Maze.size() && y >= 0 && y < Maze.size() && Maze[x][y] == 1);
}

bool RatInAMazeUtil(vector<vector<int>> Maze, int x, int y, vector<vector<int>> &Sol){
  if (x == Maze.size() - 1 && y == Maze.size() - 1 && Maze[x][y] == 1){
    Sol[x][y] = 1;
    return true;
  }

  if (isSafe(Maze, x, y) == true){
    Sol[x][y] = 1;

    if (RatInAMazeUtil(Maze, x + 1, y, Sol) || RatInAMazeUtil(Maze, x, y + 1, Sol)){
      return true;
    }

    Sol[x][y] = 0;
    return false;
  }

  return false;
}

bool RatInAMaze(vector<vector<int>> Maze){
  vector<vector<int>> Sol(Maze.size(), vector<int>(Maze.size(), 0));

  if (!RatInAMazeUtil(Maze, 0, 0, Sol)){
    cout<<"No Solution";
    return false;
  }

  Print(Sol);
  return true;
}

int main(){
  vector<vector<int>> Maze{
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {1, 1, 1, 1}
  };

  RatInAMaze(Maze);
  return 0;
}