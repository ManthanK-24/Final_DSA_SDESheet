class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
            if(i>0 && nums[i]==nums[i-1])return 1;
        return 0;
    }
};