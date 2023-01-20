//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edg)
  {
      // code here
      int ans = 0,mxw=0;
      map<int,int> mp;
      for(int i=0;i<edg.size();i++)
      {
          if(edg[i]!=-1)mp[edg[i]] += i;
      }
      for(auto x:mp){
          if(x.second > mxw)
          {
              mxw=x.second;
              ans = x.first;
          }
          else if(x.second == mxw && x.first>ans) ans = x.first;
      }
      return ans;
      
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends