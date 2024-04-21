class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int desti) {
        
        vector<int> graph[n+1];
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n+1,0);
        
        queue<int> q;
        q.push(source);
        vis[source]=1;
        
        while(!q.empty())
        {
            int frnt = q.front();
            q.pop();
            if(frnt==desti)return 1;
            
            for(auto ngbr:graph[frnt])
            {
                if(!vis[ngbr])
                {
                    q.push(ngbr);
                    vis[ngbr] = 1;
                }
            }
        }
        return 0;
        
    }
};