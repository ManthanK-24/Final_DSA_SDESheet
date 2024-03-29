//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int func(int e, int f,vector<vector<int>>& dp)
    {
        if(f==0 || f==1)return f;
        if(e==1)return f;
        if(dp[e][f]!=-1)return dp[e][f];
        
        int mn = INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int tmp = 1 + max(func(e-1,k-1,dp),func(e,f-k,dp)); // Worst Case
            mn = min(mn,tmp);  // Worst Cases Min will be our ans
        }
        return dp[e][f] = mn;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return func(n,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends