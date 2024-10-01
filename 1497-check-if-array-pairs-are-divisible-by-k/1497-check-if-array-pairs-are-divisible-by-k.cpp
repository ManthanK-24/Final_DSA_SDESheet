class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        vector<int> mp(k,0);
        
        for(auto x:arr)
        {
            int v = x%k;
            if(v<0)v+=k;
            mp[v]++;
        }
        if(mp[0]%2)return 0;
        for(int i=1;i<=k/2;i++)
        {
            if(mp[i]!=mp[k-i])return 0;
        }
        return 1;
        
    }
};