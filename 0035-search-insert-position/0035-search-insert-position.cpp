class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int lo = 0 ,hi = nums.size()-1;
        while(lo<hi)
        {
            int m = lo + (hi - lo)/2;
            if(nums[m]==target)return m;
            else if(nums[m]>target)
                hi = m;
            else
                lo = m+1;
        }
        
        return (nums[lo]<target?lo+1:lo);
    }
};