class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& ar) {
        
        
        map<int,int> mp;
        vector<int> vt;
        for(int i=0;i<ar.size();i++)
        {
            mp[ar[i]]++;
        }
        
        //cout<<mp.size()<<"\n";
        int mx = 0;
        for(auto [x,y]:mp)
        {
            if(mx<y)mx = y;
        }
        //int sz = mp.size();
        vector<vector<int>> ans(mx);
        
        for(auto [x,y]:mp)
        {
            for(int j=0;j<y;j++)
            {
                ans[j].push_back(x);
            }
        }
        return ans;
    }
};