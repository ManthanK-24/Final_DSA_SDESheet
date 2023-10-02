class Solution {
public:
    int f(int i,int j,string &s1, string &s2,vector<vector<int>> &dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int v1,v2,v3;
        if(s1[i]==s2[j]) return dp[i][j] =  0 + f(i-1,j-1,s1,s2,dp);
        
        v1 = 1 + f(i,j-1,s1,s2,dp); // insert
        v2 = 1 + f(i-1,j,s1,s2,dp); // delete
        v3 = 1 + f(i-1,j-1,s1,s2,dp); // replace
        
       return dp[i][j] = min({v1,v2,v3});
        
    }
    int minDistance(string s1, string s2) {
        
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,s1,s2,dp);
    }
};