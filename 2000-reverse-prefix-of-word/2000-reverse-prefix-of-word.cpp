class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
       for(int i=0;i<size(word);i++)
        {
            
            if(word[i]==ch)
            {
                reverse(word.begin(),word.begin()+i+1);
                break;
            }
        }
        return word;
    }
};