class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        
        int count = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int diff1 = nums[i]-k, diff2 = nums[i]+k;
            count += mp[diff1];
            count += mp[diff2];
            mp[nums[i]]++;
        }
        return count;
    }
};