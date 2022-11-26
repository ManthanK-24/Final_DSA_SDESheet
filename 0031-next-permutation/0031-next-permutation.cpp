class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k,m;
        
        for(k=nums.size()-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])break;
        }
        if(k!=-1)
        {
            for(m=nums.size()-1;m>=0;m--)
            {
                if(nums[m]>nums[k])
                {
                    swap(nums[m],nums[k]);
                    break;
                }
            }
            reverse(nums.begin()+k+1,nums.end());
        }
        else
        {
            reverse(nums.begin(),nums.end());
        }
    }
};