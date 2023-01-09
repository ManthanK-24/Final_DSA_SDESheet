//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int n, vector<int> ar) {
        // code here
        int ans=0,cry=0;
        
        for(int i=ar.size()-1;i>=0;i--)
        {
            if(ar[i]!=9)
            {
                return i+1;
            }
            else
            {
                cry = 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.solve(N, A) << "\n";
    }
    return 0;
}
    
// } Driver Code Ends