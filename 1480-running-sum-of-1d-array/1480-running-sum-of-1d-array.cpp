class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,0);
        int sum = 0;
        int i=0;
        while(i<n)
        {
            sum += nums[i];
            ans[i] = sum;
            i++;
        }
        return ans;
    }
};