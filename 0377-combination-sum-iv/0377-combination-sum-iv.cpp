class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return helper(nums,dp,target);
    }
    int helper(vector<int>& nums, vector<int>& dp, int target)
    {
        if(target==0)return 1;
        
        if(dp[target]!=-1)return dp[target];
        
        dp[target] = 0;
        for(auto x:nums)
        {
            if(x<=target) dp[target] += helper(nums,dp,target-x);
        }
        return dp[target];
    }
};