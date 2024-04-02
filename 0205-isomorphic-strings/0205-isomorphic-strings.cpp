class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        map<char,char> ms,mt;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(ms.find(s[i])==ms.end() && mt.find(t[i])==mt.end())
            {
                ms[s[i]] = t[i];
                mt[t[i]] = s[i];
            }
            else if(t[i]!=ms[s[i]] || s[i]!=mt[t[i]])
            {
                return 0;
            }
        }
        return 1;
    }
};