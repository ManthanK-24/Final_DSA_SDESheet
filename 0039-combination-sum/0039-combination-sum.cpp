class Solution {
public:
    void findSum(int idx, vector<int>& ar, vector<vector<int>>& ans,vector<int>& v, int k)
    {
        if(idx>= ar.size())
        {
            if(k==0)
            {
                ans.push_back(v);
            }
            return;
        }
        
        if(ar[idx]<=k)
        {
        v.push_back(ar[idx]);
        findSum(idx,ar,ans,v,k-ar[idx]);
        v.pop_back();
        }
        
        
        findSum(idx+1,ar,ans,v,k);
    }
    vector<vector<int>> combinationSum(vector<int>& ar, int k) {
        
        vector<vector<int>>ans;
        vector<int> v;
        findSum(0,ar,ans,v,k);
        return ans;
    }
};