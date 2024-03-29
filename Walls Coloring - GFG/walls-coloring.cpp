//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
     
    int minCost(vector<vector<int>> &colors, int n) {
        // Write your code here.
        
        vector<int> pink(n,0);
        vector<int> black(n,0);
        vector<int> yellow(n,0);
        
        pink[0] = colors[0][0];
        black[0] = colors[0][1];
        yellow[0] = colors[0][2];
        for(int i=1;i<n;i++){
            pink[i] = colors[i][0] + min(black[i-1],yellow[i-1]);
            black[i] = colors[i][1] + min(pink[i-1],yellow[i-1]);
            yellow[i] = colors[i][2] + min(pink[i-1],black[i-1]);
        }
        return min(pink[n-1],min(black[n-1],yellow[n-1]));
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends