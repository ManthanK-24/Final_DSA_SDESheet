class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int ans = 0;
        // row flip
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<n;j++)
                {
                    grid[i][j] ^= 1;
                }
            }
        }
        // col flip
        
        for(int j=0;j<n;j++)
        {
            int zer = 0, one = 0;
            for(int i=0;i<m;i++)
            {
                if(grid[i][j])one++;
                else
                    zer++;
            }
            if(zer>one)
            {
                for(int i=0;i<m;i++)
                {
                    grid[i][j] ^= 1;
                }
            }
        }
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)cout<<grid[i][j]<<" ";
        //     cout<<"#\n";
        // }
        for(int i=0;i<m;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                int x = n-j-1;
                ans += grid[i][j]<<x;
            }
          //  cout<<ans<<"ans "<<i<<"i\n";
        }
        return ans;
        
    }
};