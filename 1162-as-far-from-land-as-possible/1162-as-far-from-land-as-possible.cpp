class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,-1,1};
        int n = grid.size(), m = grid[0].size();
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j])q.push({i,j});
            }
        }
        if(q.size()==n*m)return -1;
        
        int dist = 0;
        while(q.size()){
            int size = q.size();
            dist++;
            while(size--){
                auto [xi,yi] = q.front(); q.pop();
                int newi , newj;
                for(int i=0;i<4;i++){
                    newi = xi + x[i];
                    newj = yi + y[i];
                    if(newi>=0 and newj>=0 and newi<n and newj<m and grid[newi][newj]==0)
                        q.push({newi,newj}), grid[newi][newj]=1;
                }
            }
        }
        return dist-1;
        
    }
};