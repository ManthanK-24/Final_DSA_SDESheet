class Solution {
public:
     int fn(int i , int k , vector<int>& coins,vector<vector<int>>& dp){
        if(i == 0) return (k%coins[0]) ? 1e9 :  k/coins[0];
        
        if(dp[i][k] != -1) return dp[i][k];
        
        int take = 1e9;
        if(coins[i] <= k) take = 1 + fn(i , k-coins[i] ,coins,dp);
        int nottake = fn(i-1 , k ,coins,dp);
        
        return dp[i][k] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1 , 0));
        //int ans = fn(n-1 , amount , coins,dp );
        //return (ans >= 1e9) ? -1 : ans;
        for(int j=1;j<=amount;j++)
        {
            if(j%coins[0]==0)dp[0][j] = j/coins[0];
            else
            dp[0][j] = 1e6;
        }
        for(int idx=1;idx<n;idx++)
        {
            for(int j=1;j<=amount;j++)
            {
                int notTake = dp[idx-1][j];
                int take = 1e6;
                if(coins[idx]<=j)take = 1 + dp[idx][j-coins[idx]];
                
                dp[idx][j] = min(take,notTake);
            }
        }
        return dp[n-1][amount]==1e6?-1:dp[n-1][amount];
    }
};