class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')st.push(')');
            else if(s[i]=='{')st.push('}');
            else if(s[i]=='[')st.push(']');
            else if(st.empty())return false; 
            else if(st.top()!=s[i])return false;
            else st.pop();
                
            
        
        }
        // cout<<"#\n";
        // stack<char> tmp = st;
        // while(!tmp.empty())
        // {
        //     cout<<tmp.top()<<" ";
        //     tmp.pop();
        // }
        // cout<<"$\n";
        return st.empty();
        
    }
};