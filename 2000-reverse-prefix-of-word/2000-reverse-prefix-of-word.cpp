class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
       string ans;
        bool flg = 1;
        for(auto x:word)
        {
            ans += x;
            if(x==ch && flg)
            {
                reverse(ans.begin(),ans.end());
                flg=0;
            }
        }
        return ans;
    }
};