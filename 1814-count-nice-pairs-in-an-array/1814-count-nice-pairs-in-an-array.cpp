class Solution {
public:
    int countNicePairs(vector<int>& nums) {
     
        // Brute TC:O(n*n*9) SC:O(1)
        // Optimised TC:O(n) SC:O(n)
        
        int ans = 0;
        int mod = 1e9+7;
        unordered_map<int,int> dif;
        int n = nums.size();
        
        string tmp;
        int rev = 0;
        
        for(int i=0;i<n;i++)
        {
             tmp = to_string(nums[i]);
             reverse(tmp.begin(),tmp.end());
             rev = stoi(tmp);
            //cout<<rev<<"rev ";
             ans = (ans+dif[nums[i]-rev]++)%mod;
             //dif[max(nums[i],rev)-min(nums[i],rev)]++;
              
        }
    //    cout<<"\n";
        return ans;
    }
};