//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int ar[], int n)
    {
        // code here 
        int low = 0, mid = 0, hi=n-1;
        while(mid<=hi)
        {
            if(ar[mid]==0)
            {
                swap(ar[mid],ar[low]);
                mid++;
                low++;
            }
            else if(ar[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(ar[mid],ar[hi]);
                hi--;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends