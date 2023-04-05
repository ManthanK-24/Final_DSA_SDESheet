class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size();
        long sum = 0,res = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            res = max(res, (sum+i)/(i+1));
            
        }
        // for(auto x:nums)cout<<x<<" ";
        // cout<<"\n";
        //return *max_element(nums.begin(),nums.end());
        return (int)res;
       
    }
};