class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> ans(row, vector<int>(col,-1));
        queue<pair<int,int>> q;
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
           int x = q.front().first;
           int y = q.front().second;
           q.pop();
           for(int i=0;i<4;i++)
           {
               int nx = x+dx[i];
               int ny = y+dy[i];
               if(nx>=0 and ny>=0 and nx<row and ny<col and ans[nx][ny]==-1)
               {
                   ans[nx][ny] = ans[x][y]+1;
                   q.push({nx,ny});
               }
           }
        }
        return ans;
    }
};