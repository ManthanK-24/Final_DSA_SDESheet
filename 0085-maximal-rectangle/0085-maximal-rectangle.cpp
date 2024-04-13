class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
       
        if(!size(mat))return 0;
        int area = 0;
        // int m = mat.size(), n = mat[0].size();
        int m =size(mat), n = size(mat[0]);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               
                for(int row=i, colLen = n,col;row<m && mat[row][j]=='1';row++)
                {
                    col=j;
                    while(col<n && mat[row][col]=='1')col++;
                    
                    // col is already at col+1 
                    
                    colLen = min(colLen,col-j);
                    area = max(area,(row-i+1)*colLen);
                }
            }
        }
        return area; 
       
    }
};