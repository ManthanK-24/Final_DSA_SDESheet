class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        int ans = 0;
        int symm = 0, center = 0;
        unordered_map<string,int> ucnt;
        for(int i=0;i<words.size();i++)
        {
            ucnt[words[i]]++;
        }
        string rev;
        for(int i=0;i<words.size();i++)
        {
            // symm word
            if(words[i][0]!=words[i][1])
            {
                if(ucnt[words[i]]>0)
                {
                    rev = words[i];
                    reverse(rev.begin(),rev.end());
                    if(ucnt[rev]>0)
                    {
                        ucnt[rev]--;
                        ucnt[words[i]]--;
                        ans ++; 
                    }
                }
            }
            else
            {
                if(ucnt[words[i]]>1)
                {
                    ans += ucnt[words[i]]/2;
                    ucnt[words[i]] %= 2;
                    if(ucnt[words[i]]>0)
                    {
                        center++;
                      //  cout<<ucnt[words[i]]<<"Y\t";
                    }
                }
                else if(ucnt[words[i]]>0)
                {
                    center++;
                }
                
            }
           // cout<<i<<" "<<ans<<"X\t";
        }
        ans = ans* 4;
        if(center>0)ans+=2;
      //  cout<<ans<<"#\n";
        return ans;
    }
};