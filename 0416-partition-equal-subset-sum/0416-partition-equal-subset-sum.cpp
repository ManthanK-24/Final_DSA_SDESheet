class Solution {
public:
    bool f(int idx,vector<int>& arr, int subsetSum, vector<vector<bool>>& dp){
        if(idx==0)
            return (subsetSum==arr[0]);
        if(dp[idx][subsetSum]!=false)return true;
        
        bool notTake = f(idx-1,arr,subsetSum,dp);
        bool take = false;
        if(subsetSum >= arr[idx])
        take = f(idx-1,arr,subsetSum - arr[idx],dp);
        
        return dp[idx][subsetSum] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
       int sum = 0;
        for(auto x:nums)sum += x;
        if(sum%2)return 0;
        int n = nums.size();
        
        // Memoized Code
         vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1,false));
        //return f(n-1,nums,sum/2,dp);  
        
        int halfSum = sum/2;
        // Tabulized Code 
        for(int i=0;i<n;i++)dp[i][0] = true;
        for(int j=1;j<=halfSum;j++) dp[0][j] = false;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=halfSum;j++)
            {
                // notTake
                dp[i][j] = dp[i][j] || dp[i-1][j];
                // take
                if(j>= nums[i])
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][halfSum];
        
    }
};