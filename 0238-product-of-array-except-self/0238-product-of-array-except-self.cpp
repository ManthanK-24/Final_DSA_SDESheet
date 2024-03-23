class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,0);
        int zeroCnt = 0;
        for(auto x:nums)if(x==0)zeroCnt++;
        
        if(zeroCnt>1)return ans;
        
        int prod = 1;
        
        for(auto x:nums)if(x!=0)prod *=x;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                ans[i] = prod;
            }
            else if(zeroCnt==1)
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = prod/nums[i];
            }
        }
        return ans;
        
    }
};