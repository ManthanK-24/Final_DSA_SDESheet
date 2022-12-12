//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    vector<int> cnt(27,0);
    string ans;
    for(int i=0;i<s.size();i++)
    {
        cnt[s[i]-'a']++;
        if(cnt[s[i]-'a']>1)
        {
           ans += s[i];
           break;
        }
    }
    if(!ans.size())ans+="-1";
    return ans;
}