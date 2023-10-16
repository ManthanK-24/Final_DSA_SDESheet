class Solution {
public:
    bool wb(int pos,string& s,unordered_set<string>& st,vector<bool>& mem)
    {
        // Recursion + Memoization
        if(pos==s.size())return true;
        if(mem[pos])return true;
        
        //cout<<pos<<"pos#\n";
        
        string tmp;
        for(int i=pos;i<s.size();i++)
        {
            // tmp = s.substr(pos,i-pos+1);
            tmp += s[i];
          //  cout<<i<<"i "<<tmp<<" ";
            if(st.find(tmp)!=st.end()
              &&  wb(i+1,s,st,mem))
                return mem[pos] = true;
        }
        return mem[pos] = false;
    }
    bool tabular(string s, unordered_set<string>& dict){
        if(dict.size()==0)return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string w = s.substr(j,i-j);
                    if(dict.find(w)!=dict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
     
        int n = s.size();
        unordered_set<string> st;
        for(auto x:wordDict)st.insert(x);
        vector<bool> mem(n+1,0);
       // return wb(0,s,st,mem);
        return tabular(s,st);
    }
};