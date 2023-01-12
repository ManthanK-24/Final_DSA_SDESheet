class Solution {
public:
    void placeNQ(vector<string>& tmp,vector<vector<string>>& ans, int row, int& n)
    {
        if(row==n)
        {
            ans.push_back(tmp);
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(isValid(tmp,row,col,n))
            {
                tmp[row][col] = 'Q';
                placeNQ(tmp,ans,row+1,n);
                tmp[row][col] = '.';
            }
        }
    }
    bool isValid(vector<string>& tmp, int row, int col,int n)
    {
        for(int i=0;i<row;i++)
        {
            if(tmp[i][col]=='Q')return false;
        }
        for(int j=col-1,i=row-1; j>=0 && i>=0; j--,i--)
        {
            if(tmp[i][j]=='Q')return false;
        }
        for(int j=col+1,i=row-1; j<n && i>=0; j++,i--)
        {
            if(tmp[i][j]=='Q')return false;
        } 
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> tmp(n,string(n,'.'));
        placeNQ(tmp,ans,0,n);
        return ans;
    }
};