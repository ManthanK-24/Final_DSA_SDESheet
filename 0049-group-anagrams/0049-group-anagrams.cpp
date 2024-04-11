class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());
        vector<vector<string>>ans;
        map<string,vector<int>> msidx;
        for(int i=0;i<strs.size();i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            msidx[tmp].push_back(i);
        }
        for(auto [s,vt]:msidx)
        {
            vector<string> tmp;
            for(int i=0;i<vt.size();i++)
            {
                tmp.push_back(strs[vt[i]]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};