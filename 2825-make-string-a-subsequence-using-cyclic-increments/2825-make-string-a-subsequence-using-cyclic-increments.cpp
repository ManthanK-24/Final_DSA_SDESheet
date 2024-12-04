class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        map<char,char> next;
        for(char x='a';x<'z';x++)next[x] = x+1;
        next['z']='a';
       // for(auto [x,y]:next)cout<<x<<" "<<y<<"\n";
        
        int i=0, j = 0;
        while(j<str2.size() && i<str1.size())
        {
            if(str2[j]==str1[i] ||  str2[j]==next[str1[i]])
            {
                i++;
                j++;
            }
            else
                i++;
            
                
        }
        return j==str2.size();
    }
};