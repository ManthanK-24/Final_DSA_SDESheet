class Solution {
public:
    int ans = INT_MAX;
    
    void solve(int idx,vector<int>& nums, int k,vector<int>& v){
       
        if(idx==nums.size())
        {
            int mx = 0;
            for(int i=0;i<k;i++){
                mx = max(mx,v[i]);
            }
            ans = min(ans,mx);
            return;
        }
        for(int i=0;i<k;i++){
            v[i] += nums[idx];
            solve(idx+1,nums,k,v);
            v[i] -= nums[idx];
            //if(v[i]==0)break;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        
          vector<int> v(k,0);
          solve(0,cookies,k,v);
          return ans;
    }
};