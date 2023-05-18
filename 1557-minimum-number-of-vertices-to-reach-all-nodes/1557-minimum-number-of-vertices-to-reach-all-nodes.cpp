class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vertices;
        
        unordered_map<int,int> ump;
        for(int i=0;i<edges.size();i++)ump[edges[i][1]]++;
        
        for(int i=0;i<n;i++)if(ump[i]==0)vertices.push_back(i);
        return vertices;
    }
};