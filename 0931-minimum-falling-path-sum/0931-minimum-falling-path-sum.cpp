class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)dp[0][i] = matrix[0][i];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j] += matrix[i][j];
                if(j!=0 && j!=n-1)
                {
                    dp[i][j] += min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]}); 
                }
                else
                {
                    if(j==0 && j!=n-1)
                    {
                        dp[i][j] += min(dp[i-1][j],dp[i-1][j+1]);
                    }
                    else if(j!=0 && j==n-1)
                    {
                        dp[i][j] += min(dp[i-1][j-1],dp[i-1][j]);
                    }
                    else
                    {
                        dp[i][j] += dp[i-1][j];
                    }
                    
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        for(int j=0;j<n;j++)
        {
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
        
    }
};