class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        int ans = -1;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        
        for(auto [x,y]:mp)
        {
            if(mp[-x]>0)
                ans = max(ans,-x);
            
            
        }
        return ans;
    }
};