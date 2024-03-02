class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        map<int,int> mp;
        for(auto x:nums)
        {
            
            mp[x*x]++;
        }
        vector<int> ans;
        for(auto [x,y]:mp)
        {
            //cout<<x<<"x "<<y<<"y\n";
            for(int k=0;k<y;k++)
            {
                ans.push_back(x);
            }
        }
      //  cout<<"#\n";
        return ans;
    }
};