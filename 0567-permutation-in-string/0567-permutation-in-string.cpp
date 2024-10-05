class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        map<char,int> m1,m2;
        for(auto x:s1)m1[x]++;
        
        int l = 0;
        for(int r=0;r<s2.size();r++)
        {
            
            if(r-l+1>=s1.size())
            {
                m2[s2[r]]++;
                bool ok = 1;
                for(char x='a';x<='z';x++)
                {
                    if(m1[x]!=m2[x])
                    {
                        ok = 0;
                        break;
                    }
                }
                if(ok)
                {
                    return 1;
                   // cout<<"#\n";
                }
                m2[s2[l++]]--;
            }
            else
            {
                m2[s2[r]]++;
            }
          //  cout<<l<<"l "<<r<<"r "<<m1.size()<<"m1.size() "<<m2.size()<<"m2.size()\n";
        }
      //  cout<<"#\n";
        return 0;
    }
};