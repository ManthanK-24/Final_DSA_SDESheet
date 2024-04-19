class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid )
    {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || 
           grid[r][c]!='1')return;
        
         grid[r][c]='2';
        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
        
        //grid[r][c]='1';
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int ans = 0;
        
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' )
                {
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};