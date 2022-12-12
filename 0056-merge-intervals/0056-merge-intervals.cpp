class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& itvl) {
        
        vector<vector<int>> ans;
        sort(itvl.begin(),itvl.end());
        ans.push_back(itvl[0]); 
        for(int i=1;i<itvl.size();i++)
        {
            int s = ans.size()-1;
            if(ans[s][1]>=itvl[i][0])
            {
                ans[s][1] = max(itvl[i][1],ans[s][1]);
            }
            else
             ans.push_back(itvl[i]);
            
        }
        return ans;
    }
};