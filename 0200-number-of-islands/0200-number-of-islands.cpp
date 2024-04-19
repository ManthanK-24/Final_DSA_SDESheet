class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, 
             map<vector<int>,bool>& vis)
    {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || 
           grid[r][c]!='1'|| vis[{r,c}]==1)return;
        
        vis[{r,c}]=1;
        dfs(r+1,c,grid,vis);
        dfs(r-1,c,grid,vis);
        dfs(r,c+1,grid,vis);
        dfs(r,c-1,grid,vis);
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int ans = 0;
        map<vector<int>,bool> vis;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && vis[{i,j}]==0)
                {
                    ans++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};