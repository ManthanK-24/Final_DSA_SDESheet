class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int sz = queries.size();
        vector<int> ans(sz,0);
        int n = arr.size(), curXor=0;
        vector<int> preXor(n,0);
        for(int i=0;i<n;i++)
        {
            curXor ^= arr[i];
            preXor[i] = curXor;
        }
        for(int i=0;i<sz;i++)
        {
             int val = preXor[queries[i][1]];
            if(queries[i][0]>0)
            {
                val ^= preXor[queries[i][0]-1];
            }
            ans[i] = (val);
        }
        return ans;
    }
};