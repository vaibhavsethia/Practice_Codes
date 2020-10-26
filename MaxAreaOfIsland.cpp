class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, int &Count){
        int N = grid.size(), M = grid[0].size();

        grid[i][j] = 0;
        Count++;

        if( i>0 && grid[i-1][j]==1){
          DFS(grid, i-1, j, Count);
        }       
        if( i<N-1 && grid[i+1][j]==1){
          DFS(grid, i+1, j, Count);
        }  
        if(j>0  && grid[i][j-1]==1){
          DFS(grid, i, j-1, Count);
        }         
        if(j<M-1 && grid[i][j+1]==1){
          DFS(grid,i,j+1, Count);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int Max = 0;

        for(int i=0; i<grid.size(); i++){ 
          for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j] == 1){
                int Count = 0;
                DFS(grid,i,j, Count);
                Max = Max>Count?Max:Count;
            }
          }
        }
        
      return Max;
    }
};