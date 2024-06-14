class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i=1;i<nums.size();i++)
        {
            //cout<<i<<"idx "<<nums[i]<<"nums[i] "<<nums[i-1]<<"nums[i-1] "<<cnt<<"cnt\tBEFORE\n";
            while(nums[i]<=nums[i-1])
            {
                nums[i]++;
                cnt++;
                
            }
           // cout<<i<<"idx "<<nums[i]<<"nums[i] "<<nums[i-1]<<"nums[i-1] "<<cnt<<"cnt\tAFTER\n";
        }
       // cout<<"#\n";
        return cnt;
    }
};