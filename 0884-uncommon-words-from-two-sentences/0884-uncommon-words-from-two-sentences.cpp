class Solution {
public:
    map<string,int> countStrings(string s){
        map<string,int> m;
        string tmp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                tmp += s[i];
                if(i==s.size()-1)
                {
                    m[tmp]++;
                }
            }
            else
            {
                m[tmp]++;
                tmp="";
            }
            
        }
        return m;
    }
    void solve(vector<string>& ans, map<string,int> m1,map<string,int> m2){
        for(auto [x,y]:m1)
        {
            if(y==1)
            {
                if(m2.find(x)==m2.end())
                {
                    ans.push_back(x);
                }
            }
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        map<string,int> m1,m2;
        string tmp;
        m1 = countStrings(s1);
        m2 = countStrings(s2);
        vector<string> ans;
        solve(ans,m1,m2);
        solve(ans,m2,m1);
        return ans;
        
    }
};