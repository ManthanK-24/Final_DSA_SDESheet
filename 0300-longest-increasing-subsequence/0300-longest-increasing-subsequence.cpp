class Solution {
public:
    int solve(int idx, int previdx,vector<int>&nums, vector<vector<int>>& dp)
    {
          if(idx==nums.size())return 0;
         
          if(dp[idx][previdx+1]!=-1)return dp[idx][previdx+1];
           
          // Not Take Case
         int len = 0 + solve(idx+1,previdx,nums,dp);
        // Take Case
        if(previdx==-1 || nums[idx] > nums[previdx])
        len = max(len, 1 + solve(idx+1,idx,nums,dp));
        
        return dp[idx][previdx+1]=len;
          
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};