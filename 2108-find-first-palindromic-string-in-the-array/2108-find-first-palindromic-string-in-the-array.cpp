class Solution {
public:
    bool isPalindrome(string s){
        string t = s;
        reverse(t.begin(),t.end());
        return t==s;
    }
    string firstPalindrome(vector<string>& words) {
        
        for(int i=0;i<words.size();i++)
        {
            if(isPalindrome(words[i]))
                return words[i];
        }
        return "";
    }
};