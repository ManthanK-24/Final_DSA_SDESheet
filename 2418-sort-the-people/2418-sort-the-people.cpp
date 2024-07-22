class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        vector<pair<int,string>> ds;
        vector<string> ans;
        
        for(int i=0;i<names.size();i++)
        {
            ds.push_back({-heights[i], names[i]});
        }
        sort(ds.begin(),ds.end());
        //reverse(ds.begin(),ds.end());
        for(auto [x,y]:ds)
        {
            ans.push_back(y);
        }
        return ans;
        
    }
};