class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int Dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        int m=grid.size(),n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int r=0; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                if(grid[r][c]==2) q.push({r,c});
                else if(grid[r][c]==1) fresh++;
            }
        }
        
        int minutes=0;
        while(!q.empty())
        {
            minutes++;
            int c=q.size();
            while(c-->0)
            {
                auto cur=q.front();
                q.pop();
                
                for(int d=0; d<4; d++)
                {
                    int r=cur.first+Dir[d][0];
                    int c=cur.second+Dir[d][1];
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--;
                    }
                }
            }
        }
        
        return fresh>0?-1:max(0,minutes-1);
    }
};