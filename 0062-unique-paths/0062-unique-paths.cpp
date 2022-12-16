class Solution {
public:
    int uniquePaths(int m, int n) {
     
        vector<int> prev(n,0);
        vector<int> tmp(n,0);
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                if(i==0 && j==0)tmp[j]=1;
                else{
                    
                  tmp[j] = prev[j];
                  if(j>0)tmp[j]+= tmp[j-1];
                }
            }
            prev=tmp;
        }
        return prev[n-1];
    }
};