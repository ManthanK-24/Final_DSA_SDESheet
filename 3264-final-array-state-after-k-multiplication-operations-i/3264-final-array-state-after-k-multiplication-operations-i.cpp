class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        vector<int> ans = nums;
        for(int t=0;t<k;t++)
        {
            int mnIdx = -1, mnVal = INT_MAX;
            for(int i=0;i<nums.size();i++)
            {
                if(mnVal>ans[i])
                {
                    mnVal = ans[i];
                    mnIdx = i;
                }
            }
            if(mnIdx>=0 && mnIdx<nums.size())
            {
                ans[mnIdx] = ans[mnIdx]*multiplier; 
                
            }
          // cout<<t<<"t "<<ans[mnIdx]<<"nums[mnIdx] "<<mnIdx<<"mnIdx#\n";     
        }
        return ans;
    }
};