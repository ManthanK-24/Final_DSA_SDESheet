class Solution {
public:
    int rec(int i,int j,vector<vector<int>>& grid){
        
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0)return 1e8;
        int right = grid[i][j] + rec(i,j-1,grid);
        int down = grid[i][j] + rec(i-1,j,grid);
        return min(right,down);
    }
    int memoize(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0)return 1e8;
        if(dp[i][j]!=-1)return dp[i][j];
        int right = grid[i][j] + memoize(i,j-1,grid,dp);
        int down = grid[i][j] + memoize(i-1,j,grid,dp);
        return dp[i][j]= min(right,down);
    }
    int tabulation(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)dp[i][j] = grid[i][j];
                 else
                 {
                     int up = grid[i][j];
                     if(i>0)up += dp[i-1][j];
                     else 
                         up += 1e8;
                     int left = grid[i][j];
                     if(j>0)left += dp[i][j-1];
                     else 
                         left += 1e8;
                     dp[i][j] = min(up,left);
                 }
                
            }
        }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 cout<<dp[i][j]<<" ";
            
//             }
//             cout<<"\n";
//         }
//         cout<<"x\n";
        return dp[n-1][m-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        //int n = grid.size(), m = grid[0].size();
        //vector<vector<int>> dp(n,vector<int>(m,-1));
        //return rec(n-1,m-1,grid);
       //return memoize(n-1,m-1,grid,dp);
       return tabulation(grid);
    }
};