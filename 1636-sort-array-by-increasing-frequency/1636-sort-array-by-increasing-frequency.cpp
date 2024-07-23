class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        vector<int>ans;
        map<int,int> freq;
        for(auto x:nums)freq[x]++;
        vector<vector<int>> ds;
        for(auto [y,cnty]:freq)
        {
            ds.push_back({cnty,-y});
        }
        sort(ds.begin(),ds.end());
        
        for(int i=0;i<ds.size();i++)
        {
            for(int j=0;j<(ds[i][0]);j++)
            {
                ans.push_back(-ds[i][1]);
            }
        }
        return ans;
    }
};