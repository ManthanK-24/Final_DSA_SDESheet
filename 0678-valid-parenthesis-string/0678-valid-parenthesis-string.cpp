class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> left, star;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                left.push(i);
            }
            else if(s[i]=='*')
                star.push(i);
            else
            {
                if(left.size()==0 && star.size()==0)return 0;
                
                if(left.size()>0)
                    left.pop();
                else
                    star.pop();
            }
        }
        while(left.size()>0 && star.size()>0)
        {
            if(left.top()>star.top())return 0;
            
            left.pop();
            star.pop();
        }
        return left.size()==0;
    }
};