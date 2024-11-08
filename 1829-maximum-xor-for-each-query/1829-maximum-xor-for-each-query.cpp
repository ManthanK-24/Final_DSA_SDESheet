class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int n = nums.size();
        vector<int> ans(n,0);
        int xorr = 0;
        for(auto x:nums)xorr^= x;
        int j = n-1;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0)
            {
               
               xorr ^= nums[j--];
                
                   
            }
          //  cout<<i<<"i "<<j<<"j "<<xorr<<"xorr \n";
            
                int tmp = 0;
                for(int bit=0;bit<maximumBit;bit++)
                {
                    int msk = 1<<bit;
                    if(!(msk&xorr))
                    {
                        tmp = tmp | msk;
                    }
                }
                ans[i] = tmp;
            
            
        }
      //  cout<<"#\n";
        return ans;
    }
};