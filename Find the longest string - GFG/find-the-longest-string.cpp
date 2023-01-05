//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        string res;
        int l=0;
        map<string,int> mp;
        sort(words.begin(),words.end());
        for(auto x:words)mp[x]=1;
        for(auto x:words)
        {
            bool flg = 1;
            string t;
            for(int i=0;i<x.size();i++)
            {
                t += x[i];
                if(!mp[t])
                {
                    flg=0;
                    break;
                }
            }
            if(l<x.size() && flg)
            {
                res = x;
                l = x.size();
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends