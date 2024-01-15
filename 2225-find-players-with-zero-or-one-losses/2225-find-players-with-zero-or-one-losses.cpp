class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        unordered_map<int,int> w,l;
        vector<int> v1,v2;
       
        //set<int> st;
        for(int i=0;i<matches.size();i++)
        {
            w[matches[i][0]]++;
            l[matches[i][1]]++;
        }
        
        for(auto x:w)
        { 
            if( x.second>0 && l[x.first]==0)
            {
                
                v1.push_back(x.first);
                
            }
        }
        
        for(auto x:l)
        { 
            
             if( x.second==1)
            {
                
                v2.push_back(x.first);
                
                
            }
        }
        ans.push_back(v1);
        ans.push_back(v2);
        
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};