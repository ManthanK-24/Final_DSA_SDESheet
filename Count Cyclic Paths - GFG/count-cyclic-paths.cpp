//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    #define mod (int)(1e9+7)
    int countPaths(int N){
        long long int prevO=1,prevA=0,prevB=0,prevC=0;
        for(int i=1;i<=N;i++)
        {
            int currO,currA,currB,currC;
            currO=(prevA+prevB+prevC)%mod;
            currA=(prevO+prevB+prevC)%mod;
            currB=(prevO+prevA+prevC)%mod;
            currC=(prevO+prevA+prevB)%mod;
            
            prevO=currO;
            prevA=currA;
            prevB=currB;
            prevC=currC;
        }
        return prevO;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends