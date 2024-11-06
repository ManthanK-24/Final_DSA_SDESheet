class Solution {
public:
    bool canSortArray(vector<int>& nums) {
     
        int n = nums.size();
        vector<int> one(n,0);
        for(int i=0;i<nums.size();i++)
        {
            one[i] = __builtin_popcount(nums[i]);
        }
        bool ans = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]>nums[j] && one[i]!=one[j])
                {
                    ans = 0;
                    break;
                }
            }
            if(!ans)break;
        }
        return ans;
    }
};