class Solution {
public:
    string makeFancyString(string s) {
        
        string ans; 
        
        for(int i=0;i<s.size();i++)
        {
            if(i>=2)
            {
                if(s[i]==ans[ans.size()-1] && s[i]==ans[ans.size()-2])
                    continue;
                else
                {
                    ans += s[i];
                }
                    
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};