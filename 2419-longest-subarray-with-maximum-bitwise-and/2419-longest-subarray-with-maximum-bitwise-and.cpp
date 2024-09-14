class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int mxNum = 0;
        for(int i=0;i<nums.size();i++)
        {
            mxNum = max(mxNum, nums[i]);
        }
        
        int mxLen = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==mxNum)
            {
                int curLen = 0;
                while(i<nums.size() && nums[i]==mxNum)
                {
                    curLen++;
                    i++;
                }
                mxLen = max(mxLen, curLen);
            }
        }
        return mxLen;
    }
};