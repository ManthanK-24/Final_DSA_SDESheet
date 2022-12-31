class Solution {
public:
    void findSum2(int idx, vector<int>& ar, vector<vector<int>>& ans,vector<int>& ds,int sum)
    {
        if(sum < 0 )return;
        else if(sum==0)
        {
          ans.push_back(ds);
          return;
        }
           
        else
        {
        
        for(int i=idx;i<ar.size();i++)
        {
            if(i>idx && ar[i]==ar[i-1])continue;
            ds.push_back(ar[i]);
            findSum2(i+1,ar,ans,ds,sum-ar[i]);
            ds.pop_back();
        }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& ar, int target) {
        
        sort(ar.begin(),ar.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findSum2(0,ar,ans,ds,target);
        // set<vector<int>> s;
        // for(auto x:ans)s.insert(x);
        // ans.clear();
        // for(auto x:s)ans.push_back(x);
        
        return ans;
        
    }
};