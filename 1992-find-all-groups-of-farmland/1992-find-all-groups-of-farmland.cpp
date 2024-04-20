class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>> ans;
        
        int m = land.size(), n = land[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i=0;i<land.size();i++)
        {
            for(int j=0;j<land[0].size();j++)
            {
                if(land[i][j]==1 && vis[i][j]==0)
                {
                    vector<int> tmp = {i,j};
                    int r = i;
                    while(r<m && land[r][j]==1)r++;
                    
                    if(r<m && land[r][j]==0)r--;
                    if(r==m)r--;
                    int c = j;
                    while(c<n && land[i][c]==1)c++;
                    
                    if(c<n && land[i][c]==0)c--;
                    if(c==n)c--;
                    tmp.push_back(r);
                    tmp.push_back(c);
                    ans.push_back(tmp);
                    
                    for(int x=i;x<=r;x++)
                    {
                        for(int y=j;y<=c;y++)
                        {
                            vis[x][y]=1;
                        }
                    }
                    //i=r;
                    j=c;
                }
            }
        }
        return ans;
    }
};