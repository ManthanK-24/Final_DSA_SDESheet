class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int ans = 0,x=0;
        for(auto y:nums) x=x^y;
        
        for(int i=0;i<32;i++)
        {
            int msk = 1<<i;
            bool v1 = msk&x;
            bool v2 = msk&k;
            if(v1!=v2)ans++;
        }
        return ans;
    }
};