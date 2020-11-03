class Solution {
public:
    void BFS(vector<vector<char>>& board,int& n,int& m,int i,int j){
        if(i<0||j<0||i==n||j==m){
          return;
        }
        if(board[i][j]=='X' || board[i][j]=='#'){
          return;
        }

        board[i][j] = '#';

        BFS(board,n,m,i-1,j);
        BFS(board,n,m,i+1,j);
        BFS(board,n,m,i,j-1);
        BFS(board,n,m,i,j+1);

        return;
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0){
          return;
        }
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                BFS(board,n,m,i,0);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                BFS(board,n,m,i,m-1);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                BFS(board,n,m,0,i);
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                BFS(board,n,m,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#') board[i][j] = 'O';
                else if(board[i][j]=='O') board[i][j] = 'X';
            }
        }
        return;
    }
};