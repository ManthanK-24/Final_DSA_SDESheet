//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> gar) {
        // code here
        long long ans = 0;
        int i,j=0;
        for(i=0;i<k;i++){
            ans += gar[i];
        }
        while(i<n){
            gar.push_back(ans);
            ans += ans;
            ans -= gar[j++];
            
            i++;
        }
        return gar[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends