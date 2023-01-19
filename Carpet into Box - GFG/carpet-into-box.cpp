//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        //code here
        if(a<=c && b<=d)return 0;
        
        int ans = 0;
        int c1 = min(a,b), c2 = max(a,b), b1 = min(c,d), b2 = max(c,d);
        
        while(!(c1<=b1 && c2<=b2))
        {
            if(c2>b2)
            {
                c2 = c2/2;
                if(c2<c1)swap(c1,c2);
                ans++;
            }
            else if(c1>b1)
            {
                c1 = c1/2;
                if(c1>c2)swap(c1,c2);
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends