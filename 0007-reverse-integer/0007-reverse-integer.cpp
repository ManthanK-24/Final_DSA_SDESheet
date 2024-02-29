class Solution {
public:
    string rev(string s)
    {
        string t;
        for(int i=s.size()-1;i>=0;i--)
        {
            t += s[i];
        }
        return t;
    }
    int reverse(int x) {
        string s = to_string(x);
        s = rev(s);
        if(x>=0)
        {
            long tmp = stol(s);
            long ul = 1LL<<31;
            if(tmp<= ul)
            return tmp;
            
            return 0;
        }
        else
        {
            string t = "-";
            for(int i=0;i<s.size()-1;i++)
            {
                t += s[i];
            }
            long tmp = stol(t);
            
            if(tmp>= -1LL<<31)
            return tmp;
            
            return 0;
            return stol(t);
            
        }
    }
};