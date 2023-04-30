//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int mntime = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> rottenQ;
        int vis[n][m];
        int cntFresh = 0;
        int freshThatRotted = 0;
        vector<int> drow = {0,0,1,-1};
        vector<int> dcol = {1,-1,0,0};
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
            {
                if(grid[r][c]==2)
                {
                    rottenQ.push({{r,c},0});
                    vis[r][c] = 2;
                }
                else
                vis[r][c] = 0;
                if(grid[r][c]==1)cntFresh++;
                
            }
        }
        while(!rottenQ.empty())
        {
            int r = rottenQ.front().first.first;
            int c = rottenQ.front().first.second;
            int t = rottenQ.front().second;
            mntime = max(mntime,t);
            rottenQ.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and 
                vis[nrow][ncol]!=2 and grid[nrow][ncol]==1)
                {
                    rottenQ.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                    freshThatRotted++;
                }
            }
        }
        if(cntFresh!=freshThatRotted)return -1;
        return mntime;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
