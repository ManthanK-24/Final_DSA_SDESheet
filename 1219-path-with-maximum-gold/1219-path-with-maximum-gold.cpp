class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid,int sum,int& ans)
    {
        if(r<0 || c<0 || r>=size(grid) || c>= size(grid[0]) ||
           grid[r][c]==0)return;
        int tmp = grid[r][c];
        sum += tmp;
        ans = max(ans,sum);
        
        grid[r][c] = 0;
        dfs(r,c+1,grid,sum,ans); // right
        dfs(r,c-1,grid,sum,ans); // left
        dfs(r+1,c,grid,sum,ans); // down
        dfs(r-1,c,grid,sum,ans); // up
        grid[r][c]=tmp;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        int ans = 0;
        
        for(int r=0;r<size(grid);r++)
        {
            for(int c=0;c<size(grid[0]);c++)
            {
                
                dfs(r,c,grid,0,ans);
            }
        }
        return ans;
    }
};