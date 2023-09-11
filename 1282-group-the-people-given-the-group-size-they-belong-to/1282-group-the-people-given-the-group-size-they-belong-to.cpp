class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& grp) {
        
        vector<vector<int>> ans;
        vector<pair<int,int>> vp;
        for(int i=0;i<grp.size();i++)
        {
            vp.push_back({grp[i],i});
        }
        sort(vp.begin(),vp.end());
        ans.push_back({vp[0].second});
        
        for(int i=1;i<vp.size();i++)
        {
            if(vp[i].first == vp[i-1].first && ans.back().size()<vp[i].first)
            {
                ans.back().push_back(vp[i].second);
            }
            else
            {
                ans.push_back({vp[i].second});
            }
        }
        return ans;
    }
};