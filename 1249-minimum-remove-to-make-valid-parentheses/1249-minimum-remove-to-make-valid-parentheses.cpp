class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        string ans;
        map<int,bool> valid;
        vector<int> prev;
        stack<int> stk;
        
        for(int i=0;i<s.size();i++)
        {
            if(i>0)
            {
                if(s[i]=='(')
                {
                    stk.push(i);
                    
                }
                else if(s[i]==')')
                {
                    if(stk.size()>0)
                    {
                        valid[i] = 1;
                        valid[stk.top()]=1;
                        stk.pop();
                    }
                }
            }
            else
            {
                if(s[i]=='(')
                {
                    stk.push(i);
                }
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' or s[i]==')')
            {
                if(valid[i]==1)ans += s[i];
            }
            else
                ans += s[i];
        }
        return ans;
    }
};