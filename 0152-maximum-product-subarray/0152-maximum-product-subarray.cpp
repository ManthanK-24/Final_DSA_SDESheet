class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // Brute TC:O(n^3) SC:O(1)
        // Improved TC:O(n^2) SC:O(1)
        // Optimal TC:O(n) SC:O(1)
        
        int ans = INT_MIN;
        int pre = 1, suf=1;
        for(int i=0;i<nums.size();i++){
            if(pre==0)pre=1;
            if(suf==0)suf=1;
            pre = pre*nums[i];
            suf = suf*nums[nums.size()-i-1];
            ans = max({ans,pre,suf});
        }
        return ans;
        
    }
};