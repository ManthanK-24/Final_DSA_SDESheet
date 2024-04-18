class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int peri = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    // check up side
                    if(i==0)peri += 1;
                    else
                    {
                        if(grid[i-1][j]!=1)peri+=1;
                    }
                    
                    // check down side
                    if(i==m-1)peri +=1;
                    else
                    {
                        if(grid[i+1][j]!=1)peri +=1;
                    }
                    // check left side
                    if(j==0)peri += 1;
                    else
                    {
                        if(grid[i][j-1]!=1)peri += 1;
                    }
                    // check righ side
                    if(j==n-1)peri += 1;
                    else
                    {
                        if(grid[i][j+1]!=1)peri += 1;
                    }
                }
            }
        }
        return peri;
    }
};