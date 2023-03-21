class Solution {
public:
    bool canFinish(int nC, vector<vector<int>>& preReq) {
        vector<vector<int>> graph(nC);
        for(auto ele:preReq)
        {
            graph[ele[1]].push_back(ele[0]);
        }
        vector<int> deg = computeDegrees(graph);
        
        for(int i=0;i<nC;i++)
        {
            int j=0;
            for(;j<nC;j++)
            {
                if(!deg[j])
                {
                    break;
                }
            }
            if(j==nC)return 0;
            deg[j]--;
            for(int v:graph[j])
            {
                deg[v]--;
            }
        }
        return true;
    }
    vector<int> computeDegrees(vector<vector<int>>& g)
    {
        vector<int> degrees(g.size(),0);
        for(auto adj:g)
        {
            for(int v:adj)
            {
                degrees[v]++;
            }
        }
        return degrees;
    }
};