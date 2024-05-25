class Solution {
public:

void solve(int idx, string &s, unordered_set<string>& st,vector<string>& ans,
                vector<string>& tmp)
{
    if(idx==s.size())
    {
        string sentence;
        for(auto it:tmp)
        {
            sentence += it;
            sentence += " ";
        }
        sentence.pop_back();
        ans.push_back(sentence);
       return;
    }
    string x;
    for(int i=idx;i<s.size();i++)
    {
        x += s[i];
        if(st.find(x)!=st.end())
        {
            tmp.push_back(x);
            solve(i+1,s,st,ans,tmp);
            tmp.pop_back();
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    vector<string> tmp;
    unordered_set<string> st(dictionary.begin(),dictionary.end());
    solve(0,s,st,ans,tmp);
    return ans;
}
};