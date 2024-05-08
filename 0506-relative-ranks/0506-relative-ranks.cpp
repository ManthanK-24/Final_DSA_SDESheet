class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        
        vector<pair<int,int>> vp; // {score,idx}
        
        for(int i=0;i<size(score);i++)
        {
            vp.push_back({score[i],i});
            ans.push_back(to_string(i));
        }
        sort(vp.begin(),vp.end());
        
        for(int i=0;i<vp.size();i++)
        {
            int j = vp.size()-i-1;
            if(i==0)
            {
                ans[vp[j].second] = "Gold Medal";
            }
            else if(i==1)
            {
                 ans[vp[j].second] = "Silver Medal";
            }
            else if(i==2)
            {
                 ans[vp[j].second] = "Bronze Medal";
            }
            else
            {
                 ans[vp[j].second] = to_string(i+1);
            }
        }
        return ans;
    }
};