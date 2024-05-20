class Solution {
public:
    void solve(int idx,vector<int>& nums,int xorr,int& ans)
    {
        if(idx==size(nums))
        {
            ans += xorr;
            return;
        }
        
        
        // pick 
      //  cout<<"pick "<<idx<<"idx "<<xorr<<"xorr "<<ans<<"ans\n";
        solve(idx+1,nums,xorr^nums[idx],ans);
        
         // not pick
      //  cout<<"not pick "<<idx<<"idx "<<xorr<<"xorr "<<ans<<"ans\n";
        solve(idx+1,nums,xorr,ans);
    }
    int subsetXORSum(vector<int>& nums) 
    {
       int ans = 0;
        solve(0,nums,0,ans);
      //  cout<<"#\n";
        return ans;
    }
};