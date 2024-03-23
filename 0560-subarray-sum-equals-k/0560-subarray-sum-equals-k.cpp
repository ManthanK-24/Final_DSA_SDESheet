class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int cnt = 0;
        int sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        { 
            sum += nums[i];
            if(sum==k )cnt++; 
            
            cnt += mp[sum-k];
            
            //if(nums[i]==k && k==0 && sum!=k)cnt++;
            mp[sum]++;
            
        }
        return cnt;
    }
};