class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
     
        vector<int> ans;
        
        for(int c=0;c<matrix[0].size();c++)
        {
           int cmx = 0;

            for(int r=0;r<matrix.size();r++) 
            {
            int rmn = *min_element(matrix[r].begin(),matrix[r].end());
             
             int cmx =0;
                for(int k=0;k<matrix.size();k++)
                {
                    cmx = max(cmx,matrix[k][c]);
                }
                if(cmx==matrix[r][c] && rmn ==cmx)ans.push_back(cmx);
             }
        }
        return ans;
    }
};