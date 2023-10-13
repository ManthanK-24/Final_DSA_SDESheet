class Solution {
public:
    int f(int idx,vector<int>& cost,vector<int>& dp)
    {
        if(idx<=0)return 0;
        
         if(dp[idx]!=-1)return dp[idx];   
        
        int last = f(idx-1,cost,dp);
        if(idx>=1) last += cost[idx-1];
            
        int secondLast = f(idx-2,cost,dp);
        if(idx>=2) secondLast += cost[idx-2];
        
        return dp[idx]=min(last,secondLast);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return f(n,cost,dp);
    }
};