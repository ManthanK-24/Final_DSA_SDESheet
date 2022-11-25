class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // A1 Brute Force TC:O(m*n) SC:O(m*n) 
        // A2 Using separate set for row and col TC:O(m*n) SC:O(m+n)
        // A3 TC:O(m*n) SC:O(1) -> extra
        
        bool frow=0, fcol=0;
        for(int i=0;i<matrix.size();i++)if(matrix[i][0]==0)fcol=1;
        for(int j=0;j<matrix[0].size();j++)if(matrix[0][j]==0)frow=1;
        
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(frow)for(int j=0;j<matrix[0].size();j++)matrix[0][j]=0;
        if(fcol)for(int i=0;i<matrix.size();i++)matrix[i][0]=0;
    } 
};