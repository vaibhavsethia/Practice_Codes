class Solution {
public:
  void DFS(vector<vector<char>>& grid, int i, int j){
    int N = grid.size();
    int M = grid[0].size();
    
    grid[i][j] = '0';
        
    if( i>0 && grid[i-1][j]=='1' ){
      DFS(grid, i-1, j);
    }       
    if( i<N-1 && grid[i+1][j]=='1' ){
      DFS(grid, i+1, j);
    }  
    if(j>0  && grid[i][j-1]=='1'){
      DFS(grid, i, j-1);
    }         
    if(j<M-1 && grid[i][j+1]=='1' ){
      DFS(grid,i,j+1);
    }  
  }
   

  int numIslands(vector<vector<char>>& grid) {
      int Count=0;

        for(int i=0; i<grid.size(); i++){ 
          for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j] == '1'){
                Count++;    
                DFS(grid,i,j);
            }
          }
        }
        
      return Count;
  }
};