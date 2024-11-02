class Solution {
public:
    bool isCircularSentence(string s) {
        
        char firstChar, lastChar, curChar;
        
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            {
                if(!(firstChar>='a' && firstChar<='z') && 
                   !(firstChar>='A' && firstChar<='Z'))
                {
                    firstChar=s[i];
                }
                lastChar = s[i];
            }
            else
            {
                if(i+1<s.size())
                {
                    if(s[i+1]!=lastChar)return 0;
                }
            }
        }
        return lastChar==firstChar;
    }
};