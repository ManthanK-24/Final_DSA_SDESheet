class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        map<string,int> mp;
        int m = matrix.size(), n=matrix[0].size();
        
        string s1,s2;
        for(int i=0;i<m;i++)
        {
            s1.clear();
            s2.clear();
            for(int j=0;j<n;j++)
            {
                s1 += to_string(matrix[i][j]);
                s2 += to_string(1^matrix[i][j]);
            }
            mp[s1]++;
            mp[s2]++;
        }
        int mx = 0;
        for(auto [x,y]:mp)
        {
            mx = max(mx,y);
        }
        return mx;
    }
};