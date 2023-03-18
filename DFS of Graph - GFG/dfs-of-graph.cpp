//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     void dfs(int v, int x,vector<int> adj[],vector<int>& ans){
         if(vis.find(x)==vis.end())
         {
             ans.push_back(x);
             vis[x]++;
             for(int j=0;j<adj[x].size();j++)
             {
                 if(vis.find(adj[x][j])==vis.end())
                 {
                     dfs(v,adj[x][j],adj,ans);
                 }
             }
         }
         else
         return;
     }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        dfs(v,0,adj,ans);
        return ans;
    }
    private:
    unordered_map<int,int> vis;
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends