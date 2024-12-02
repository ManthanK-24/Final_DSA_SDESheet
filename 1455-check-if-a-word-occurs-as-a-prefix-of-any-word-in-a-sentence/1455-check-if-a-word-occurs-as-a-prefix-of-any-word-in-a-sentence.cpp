class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int j=0,cur=1;
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]>='a' && sentence[i]<='z')
            {
                if(j<searchWord.size() && sentence[i]==searchWord[j])
                {
                    j++;
                }
                else if(j<searchWord.size() && sentence[i]!=searchWord[j])
                {
                    j=0;
                    cur++;
                    while(sentence[i]>='a' && sentence[i]<='z')i++;
                    
                }
                else 
                    return cur;
            }
            else
            {
                if(j==searchWord.size())return cur;
                j=0;
                cur++;
            }
            
        }
        if(j==searchWord.size())return cur;
        return -1;
    }
};