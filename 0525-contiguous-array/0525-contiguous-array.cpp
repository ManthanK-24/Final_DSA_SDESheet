class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int ans = 0;
        map<int,int> mp;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)sum -= 1;
            else
                sum += 1;
            if(sum==0)
            {
                ans = i+1;
            }
            else if(mp.find(sum)!=mp.end())
            {
                ans = max(ans, i-mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return ans;
    }
};