class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n,0); // 0:uncolored, 1: colorA, -1:colorB
        queue<int> q;
    
        for(int i=0;i<n;i++)
        {
            if(color[i])continue;
            color[i] = 1;
            for(q.push(i);!q.empty();q.pop())
            {
                int cur = q.front();
                for(auto ngbr:graph[cur])
                {
                    if(!color[ngbr])
                    {
                        color[ngbr] = -color[cur];
                        q.push(ngbr);
                    }
                    else if(color[ngbr]==color[cur])return false;
                    
                }
            }
            
        }
        return true;
    }
};