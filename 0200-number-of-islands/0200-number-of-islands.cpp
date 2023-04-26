class Solution {
    private: 
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int r,int c )
    {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({r,c});
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 and ny>=0 and nx<n and ny<m and 
                   grid[nx][ny]=='1' and !vis[nx][ny] )
                {
                    vis[nx][ny] = 1 ;
                    q.push({nx,ny});
                }
            }
        }
          
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]=='1' and !vis[i][j])
               {
                   ans++;
                   bfs(grid,vis,i,j);
               }
           }
        }
        return ans;
    }
};