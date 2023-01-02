class Solution {
public:
    bool isPalindrome(string s)
    {
         string s1 = s;
        reverse(s.begin(),s.end());
        return s1==s;
    }
    void helper(int idx,string s, vector<string>& path, vector<vector<string>>& ans)
    {
        if(idx==s.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<s.size();++i)
        {
            if(isPalindrome(s.substr(idx,i-idx+1)))
            {
                path.push_back(s.substr(idx,i-idx+1));
                helper(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(0,s,path,ans);
        return ans;
    }
};