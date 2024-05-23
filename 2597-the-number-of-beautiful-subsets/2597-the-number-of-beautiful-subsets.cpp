class Solution {
    private: 
    int helper(vector<int>&nums,int k, unordered_map<int,int>& freq, int idx)
    {
        if(idx==size(nums))
        {
            return 1;
        }
        
        int ans = helper(nums,k,freq,idx+1);
        if(!freq[nums[idx]-k])
        {
            freq[nums[idx]]++;
            ans += helper(nums,k,freq,idx+1);
            freq[nums[idx]]--;
        }
        return ans;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        sort(nums.begin(),nums.end());
        
        return helper(nums,k,freq,0)-1;
    }
};