vector<int> createLPS(string pattern)
{
    vector<int> lps(pattern.size());
    lps[0] = 0;
    int length = 0, i=1;
    
    while(i<pattern.size())
    {
        if(pattern[i]==pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if(length!=0)length = lps[length-1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
vector<int> KMPSearch(string text, string pattern)
{
    vector<int> matches;
    vector<int> lps = createLPS(pattern);
    int i = 0, j=0;
    while(i<text.size())
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        if(j==pattern.size())
        {
            matches.push_back(i-j);
            j = lps[j-1];
        }
        else if(i<text.size() && text[i]!=pattern[j])
        {
            if(j!=0)j=lps[j-1];
            else
            {
                i++;
            }
        }
    }
    return matches;
}
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        vector<int> ans;
        vector<int> ia = KMPSearch(s,a);
        vector<int> ib = KMPSearch(s,b);
        
        for(int x:ia)
        {
            auto lb = lower_bound(ib.begin(),ib.end(),x-k);
            auto ub = upper_bound(ib.begin(),ib.end(),x+k);
            if(ub-lb>0)ans.push_back(x);
        }
        return ans;
    }
};