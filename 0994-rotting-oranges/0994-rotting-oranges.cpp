class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())return 0;
        int m = grid.size(), n = grid[0].size(), tot=0,days=0,cnt=0;
        
        queue<pair<int,int>> rotten;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)rotten.push({i,j});
                if(grid[i][j]!=0)tot++;
            }
        }
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k;
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                int dx[4] = {0,0,1,-1};
                int dy[4] = {1,-1,0,0};
                for(int i=0;i<4;i++){
                    int nx = x + dx[i], ny = y+dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1){
                        continue;
                    }
                    grid[nx][ny] = 2;
                    rotten.push({nx,ny});
                    
                }
            }
            if(!rotten.empty())days++;
        }
      //  cout<<tot<<" "<<cnt<<" "<<days<<"#\n";
        return tot==cnt?days:-1;
        
    }
};