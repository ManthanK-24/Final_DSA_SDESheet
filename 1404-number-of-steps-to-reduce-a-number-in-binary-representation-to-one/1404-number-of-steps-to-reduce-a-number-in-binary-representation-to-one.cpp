class Solution {
public:
    string rightShift(string s)
    {
        string t;
        t += '0';
        t += s;
        t.pop_back();
        return t;
    }
    bool check(string s)
    {
        if(s.back()!='1')return 0;
        int cnt = 0;
        for(auto x:s)
        {
            if(x=='1')cnt++;
        }
        return cnt==1;
    }
    string addOne(string s)
    {
        reverse(s.begin(),s.end());
        int carry = 1;
        
        for(int i=0;i<s.size();i++)
        {
            if(carry==1)
            {
                if(s[i]=='1')
                {
                    s[i]='0';
                }
                else
                {
                    s[i]='1';
                    carry = 0;
                }
            }
            
        }
        if(carry)
        s += '1';
        reverse(s.begin(),s.end());
        return s;
    }
    int numSteps(string s)
    {
          int cnt =0;
        while(!check(s))
        {
            if(s.back()=='1')
            {
                s = addOne(s);
            }
            else
            {
                s = rightShift(s);
            }
            cnt++;
        }
        return cnt;
    }
};