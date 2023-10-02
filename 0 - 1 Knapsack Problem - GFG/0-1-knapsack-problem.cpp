//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int maxWeight, int wt[], int val[], int n) 
    { 
       // Your code here
       
       // Brute Force - Recursive TC:O(2^n) SC:O(n) 
       // Memoization(Top Down) - TC:O(N*MaxWeight) 
       // SC:O(N*MaxWeight) + O(N) Auxilary Stack Space
       // Tabulation(Bottom Up) - TC:O(N*MaxWeight)
       // SC:O(N*MaxWeight) => Optimised
       // SC:O(Maxweight)
       
       vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
       for(int W=wt[0];W<=maxWeight;W++) dp[0][W] = val[0];
       
       for(int idx=1;idx<n;idx++)
       {
           for(int W=0;W<=maxWeight;W++)
           {
               int notTake = 0 + dp[idx-1][W];
               
               int take = INT_MIN;
               if(wt[idx]<= W)
               take = val[idx] + dp[idx-1][W-wt[idx]];
               
               dp[idx][W] = max(take,notTake);
           }
       }
       return dp[n-1][maxWeight]; 
       
      /* vector<int> prev(maxWeight+1,0), cur(maxWeight+1,0); 
       for(int W=0;W<=maxWeight;W++) prev[W] = val[0];
       
       for(int idx=1;idx<n;idx++)
       {
           for(int W=0;W<=maxWeight;W++)
           {
               int notTake = 0 + prev[W];
               int take = INT_MIN;
               if(wt[idx]<=W)
               take = val[idx] + prev[W-wt[idx]];
               cur[W] = max(take,notTake);
           }
           prev = cur;
       }
       return prev[maxWeight]; */
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends