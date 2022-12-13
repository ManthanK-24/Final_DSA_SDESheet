class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int lo = 0, hi = n*m-1;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            int v = mat[mid/m][mid%m];
            //cout<<lo<<" "<<mid<<" "<<hi<<"\n";
           // cout<<v<<" "<<mid/m<<" "<<mid%m<<"#\n";
            
            if(v==tar)
                return true;
            else if(v<tar)
                lo = mid+1;
            else if(v>tar)
                hi = mid-1;
        }
        return false;
    }
};