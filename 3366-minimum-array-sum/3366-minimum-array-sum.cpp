class Solution {
public:
    int solve(vector<int>& nums, vector<vector<vector<int>>>& dp, int idx,int k, int op1, int op2)
    {
        if(idx==nums.size())return 0;
        
        if(dp[idx][op1][op2]!=-1)return dp[idx][op1][op2];
        
        int ans = INT_MAX;
        // five cases
        // 1. Only op1
        // 2. Only op2
        // 3. Op1Op2
        // 4. Op2Op1
        // 5. None

        //  1. Only Op1
        if(op1>0)
        {
        int sumOp1 = ceil(nums[idx]/2.0) + solve(nums,dp,idx+1,k,op1-1,op2);
        ans = min(ans,sumOp1);
        }
        
        // 2. Only Op2
        if(op2>0 && nums[idx]>=k)
        {
            int sumOp2 = nums[idx]-k + solve(nums,dp,idx+1,k,op1,op2-1);
            ans = min(ans,sumOp2);
        }
        if(op1>0 && op2>0)
        {
            int afterOp1 = ceil(nums[idx]/2.0);
            if(afterOp1>=k)
            {
                // 3. Op1Op2
                int sumOp1Op2 = afterOp1-k + solve(nums,dp,idx+1,k,op1-1,op2-1);
                ans = min(ans,sumOp1Op2);
            }
            if(nums[idx]>=k)
            {
                // 4. Op2Op1
                int sumOp2Op1 = ceil((nums[idx]-k)/2.0) + solve(nums,dp,idx+1,
                                                                k,op1-1,op2-1);
                ans = min(ans,sumOp2Op1);
            }
        }
        // 5. None
        int sumNone = nums[idx] + solve(nums,dp,idx+1,k,op1,op2);
        
        ans = min(ans,sumNone);
        
        return dp[idx][op1][op2] = ans;
        
        
        
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));
        return solve(nums,dp,0,k,op1,op2);
    }
};