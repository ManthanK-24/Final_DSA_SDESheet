class Solution {
public:
    void findAllSubset(int idx,vector<int>& ar, vector<vector<int>>& ans, vector<int>& v)
    {
        if(idx>=ar.size())
        {
            ans.push_back(v);
            return;
        }
        v.push_back(ar[idx]);
        findAllSubset(idx+1,ar,ans,v);
        v.pop_back();
        findAllSubset(idx+1,ar,ans,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& ar) 
    {
       vector<vector<int>> ans;
        vector<int> v;
        findAllSubset(0,ar,ans,v);
        sort(ans.begin(),ans.end());
        set<vector<int>> s;
        for(auto x:ans)
        {  
            v = x; 
            sort(v.begin(),v.end());
            s.insert(v);
        }
        ans.clear();
        for(auto x:s)ans.push_back(x);
        
        return ans;
    }
};