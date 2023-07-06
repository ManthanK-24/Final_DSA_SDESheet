class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int minLen = INT_MAX;
        int cur = 0, sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(sum>=target)
            {  minLen = min(minLen,i-cur+1);
                while(sum>=target && cur<=i)
                {
                    minLen = min(minLen,i-cur+1);
                    sum -= nums[cur];
                    cur++;
                }
            }
        }
        return minLen==INT_MAX?0:minLen;
    }
};