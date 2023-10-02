int solveRec(int curr, int prev, int arr[], int n)  
    {
       if(curr == n) return 0;
       
       int incl = 0;
       if(prev == -1 || arr[curr] > arr[prev]) 
        incl = arr[curr] + solveRec(curr+1,curr,arr,n);
        
       int excl = 0 + solveRec(curr+1, prev,arr,n);
       
       return max(incl,excl);
    }
    
    int solveMem(int curr, int prev, int arr[], int n,vector<vector<int>>&dp)
    {
       if(curr == n) return 0;
       
       if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
       
       int incl = 0;
       if(prev == -1 || arr[curr] > arr[prev]) 
        incl = arr[curr] + solveMem(curr+1,curr,arr,n,dp);
        
       int excl = 0 + solveMem(curr+1, prev,arr,n,dp);
       
       return dp[curr][prev+1] = max(incl,excl);
    }
    
    int solveTab(int arr[], int n)                      

 // Maximum sum increasing subsequence
    {
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
               
        int incl = 0;
       if(prev == -1 || arr[curr] > arr[prev]) 
        incl = arr[curr] + dp[curr+1][curr+1];
        
       int excl = 0 + dp[curr+1][prev+1];
       
        dp[curr][prev+1] = max(incl,excl); 
            }
        }
        return dp[0][-1+1];
    }
    
    int solveSpace(int arr[], int n)
    {
        vector<int>cur(n+1,0);
        vector<int>next(n+1,0);
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
               
        int incl = 0;
       if(prev == -1 || arr[curr] > arr[prev]) 
        incl = arr[curr] + next[curr+1];
        
       int excl = 0 + next[prev+1];
       
        cur[prev+1] = max(incl,excl); 
            }
            
            next = cur;
        }
        return next[-1+1];
    }
     
     int solveSpace1D(int arr[], int n)
     {
         vector<int>curr(n,0);
         int ans = 0;
         
         for(int i=0; i<n; i++){
             curr[i] = arr[i];
            
            for(int j =0; j<i; j++){
                if(arr[i] > arr[j])
                 curr[i] = max(curr[i], curr[j]+arr[i]);
            }
             ans = max(ans,curr[i]);
         }
           return ans;
     }
    int maxSumIS(int arr[], int n)  
    {  
        // Your code goes here
       // return solveRec(0,-1,arr,n);
        
       // vector<vector<int>>dp(n, vector<int>(n+1,-1));
       // return solveMem(0,-1,arr,n,dp);
        
       // return solveTab(arr,n);
       
       return solveSpace(arr,n);
        
        
    }  
