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
        vector<vector<int>> dp(n, vector<int>(amount+1 , -1));
        int ans = fn(n-1 , amount , coins,dp );
        return (ans >= 1e9) ? -1 : ans;
    }
};