//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int m, int n, vector<vector<int>> a) {
       // code here
       int l=0,r=n-1,b=m-1,t=0;
       while(l<r && t<b){
           int x=a[t+1][l];
           for(int i=l;i<=r;i++)swap(x,a[t][i]);
           t++;
           for(int i=t;i<=b;i++)swap(x,a[i][r]);
           r--;
           for(int i=r;i>=l;i--)swap(x,a[b][i]);
           b--;
           for(int i=b;i>=t;i--)swap(x,a[i][l]);
           l++;
       }
       return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends