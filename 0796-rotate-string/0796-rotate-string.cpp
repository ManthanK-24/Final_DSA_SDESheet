class Solution {
public:
    string rotateByOne(string s){
        string ans;
        for(int i=1;i<s.size();i++)
            ans += s[i];
        ans += s[0];
        return ans;
    }
    bool rotateString(string s, string goal) {
        
        if(s==goal)return 1;
        string tmp=s;
        for(int i=0;i<s.size();i++)
        {
            tmp = rotateByOne(tmp);
            if(tmp==goal)return 1;
        }
        return 0;
    }
};