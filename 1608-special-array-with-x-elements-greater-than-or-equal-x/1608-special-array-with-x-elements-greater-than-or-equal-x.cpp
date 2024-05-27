class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        
        for(int x=0;x<=size(nums);x++)
        {
            int cnt = 0;
            for(int i=0;i<size(nums);i++)
            {
                if(nums[i]>=x)
                {
                    cnt++;
                }
            }
            if(cnt==x)
            {
                return x;
            }
        }
        return -1;
    }
};