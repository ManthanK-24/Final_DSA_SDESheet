//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(int i, int j,string s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
        
    }
    int f(int idx, string& s,vector<int>&dp)
    {
        if(idx==s.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        
       // string tmp="";
        int mnCost = INT_MAX;
        for(int j=idx;j<s.size();j++)
        {
           // tmp += s[j];
            if(isPalindrome(idx,j,s))
              {
                  int cost = 1 + f(j+1,s,dp);
                  mnCost = min(mnCost,cost);
              }
        }
        return dp[idx]=mnCost;
    }
    int palindromicPartition(string str)
    {
        // code here
        vector<int> dp(str.size(),-1);
        return f(0,str,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends