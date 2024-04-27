class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int sz = size(nums);
        int ans = 0, df = INT_MAX;
        for(int i=0;i<sz;i++)
        {
            int j = i+1;
            int k = sz-1;
            while(j<k)
            {    
                int sum = nums[i] + nums[j] + nums[k];
                if(df> abs(sum-target))
                {
                    df = abs(sum-target);
                    ans = sum;
                }
                if(sum > target)
                {
                    k--;
                }
                else if(sum<target)
                {
                    j++;
                }
                else
                {
                    ans = target;
                    break;
                }
            }
            if(ans==target)break;
        }
        return ans;
    }
};