class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
    
        for(auto &x:nums)
        {
            if(x<0)
            {
                x = -1*x;
            }
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            nums[i] *= nums[i];
        }
        return nums;
    }
};