//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>> vm;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            vm.push_back({end[i],start[i],i+1});
        }
        sort(vm.begin(),vm.end());
        int limit = vm[0][0];
        ans.push_back(vm[0][2]);
        for(int i=1;i<n;i++)
        {
            if(vm[i][1]> limit)
            {
                limit = vm[i][0];
                ans.push_back(vm[i][2]);
            }
            
        }
        return ans.size();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends