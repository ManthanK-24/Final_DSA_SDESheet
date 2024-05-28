class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int len = 0;
        int tmpC = 0;
        int l = 0;
        for(int r=0;r<size(s);r++)
        {
            int df = abs(s[r]-t[r]);
            tmpC += df;
            
            if(tmpC<=maxCost)
            {
                len = max(len,r-l+1);
            }
            else
            {
                while(tmpC>maxCost)
                {
                    int df = abs(s[l]-t[l]);
                    tmpC -= df;
                    l++;
                }
                len = max(len,r-l+1);
            }
        }
        return len;
    }
};