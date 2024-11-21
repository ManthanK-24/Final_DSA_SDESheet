class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m,vector<int>(n,0));
        
        for(int i=0;i<walls.size();i++)
        {
            int x = walls[i][0], y = walls[i][1];
            v[x][y] = -2;
        }
        for(int i=0;i<guards.size();i++)
        {
            int x = guards[i][0], y = guards[i][1];
            v[x][y] = 2;
        }
        for(int i=0;i<guards.size();i++)
        {
            int x = guards[i][0], y = guards[i][1];
            // up
            for(int c=y-1;c>=0;c--)
            {
                if(v[x][c]==-2 || v[x][c]==2)break;
                v[x][c] = 1;
            }
            // down
            for(int c=y+1;c<n;c++)
            {
                if(v[x][c]==-2 || v[x][c]==2)break;
                v[x][c] = 1;
            }
            //right
            for(int r=x+1;r<m;r++)
            {
                if(v[r][y]==-2 || v[r][y]==2)break;
                v[r][y] = 1;
            }
            // left
            for(int r=x-1;r>=0;r--)
            {
                if(v[r][y]==-2 || v[r][y]==2)break;
                v[r][y] = 1;
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==0)ans++;
            }
        }
        return ans;
    }
};