class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size(), m=matrix[0].size();
        vector<int> dp(m, 0);
        
        int minValue=INT_MAX, secondMinValue=INT_MAX, minValueIndex, prevMinValue, prevSecondMinValue, prevMinValueIndex;
        
        // time O(m*n)
        // space O(m)
        for(int i=0; i<n; i++) 
        {
            prevMinValue=minValue;
            prevSecondMinValue=secondMinValue;
            prevMinValueIndex=minValueIndex;
            minValue=INT_MAX, secondMinValue=INT_MAX;
            
            for(int j=0; j<m; j++) 
            {
                if(i==0) 
                {
                    dp[j]=matrix[i][j];
                } 
                else 
                {
                    dp[j] = (j==prevMinValueIndex ? prevSecondMinValue : prevMinValue)
                        + matrix[i][j];
                }
                if(dp[j] < minValue)
                {
                    secondMinValue = minValue;
                    minValueIndex=j;
                    minValue=dp[j];
                }
                else if(dp[j] < secondMinValue)
                {
                    secondMinValue=dp[j];
                }
            }
           /* cout<<i<<"i\n";
            for(int j=0;j<m;j++)
            {
                cout<<j<<"j "<<dp[j]<<"dp[j]\t";
            }
            cout<<"\n"; */
        }
        
        
        return *min_element(dp.begin(), dp.end());
    }
};