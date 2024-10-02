class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        if(n==0)return {};
        map<int,int> mp;
        vector<int> ans(n,0), tmp(n,0);
        for(int i=0;i<n;i++)tmp[i] = arr[i];
        sort(tmp.begin(),tmp.end());
        mp[tmp[0]] = 1;
        for(int i=1;i<n;i++)
        {
            mp[tmp[i]] = mp[tmp[i-1]];
            if(tmp[i]!=tmp[i-1])
            {
                mp[tmp[i]] += 1;
            }
        }
        for(int i=0;i<n;i++)
        {
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};