class Solution {
public:
    bool isPaliHelper(string s){
        string t = s;
        reverse(t.begin(),t.end());
        return t==s;
    }
    bool isPalindrome(string s) {
        
        string t;
        for(auto x:s)
        {
            if((x>='a' && x<='z') || (x>='0' && x<='9'))
            {
                t += x;
            }
            else if(x>='A' && x<='Z')
            {
                t += tolower(x);
            }
        }
        return isPaliHelper(t);
        
    }
};