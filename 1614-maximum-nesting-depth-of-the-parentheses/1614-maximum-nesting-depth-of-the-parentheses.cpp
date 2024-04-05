class Solution {
public:
    int maxDepth(string s) {
        
        stack<char> stk;
        int ans = 0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                stk.push(s[i]);
                int sz = stk.size();
                ans = max(ans,sz); 
            }
            else if(s[i]==')')
            {
                stk.pop();
            }
        }
        return ans;
    }
};