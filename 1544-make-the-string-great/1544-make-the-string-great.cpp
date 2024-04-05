class Solution {
public:
    bool similar(char x, char y)
    {
        if(x<y)
            swap(x,y);
        char z = y;
        
       
        if(x!=y && x==tolower(y))return 1;
        
        if(x!=z && toupper(x)==z)return 1;
        
        return 0;
    }
    string makeGood(string s) {
        
        string ans;
        stack<char> stk;
        //sort(s.begin(),s.end());
        //return s;
        for(int i=0;i<s.size();i++)
        {
            if(stk.size()>0)
            {
                char x = stk.top();
                
                if(similar(s[i],x))
                {
                    stk.pop();
                }
                else
                    stk.push(s[i]);
            }
            else
                stk.push(s[i]);
            
        }
        // while(stk.size()>0)
        // {
        //     cout<<stk.top()<<" ";
        //     stk.pop();
        // }
      //  cout<<"#\n";
        while(stk.size()>0)
        {
            if(stk.size()>1)
            {
                char x = stk.top();
                stk.pop();
                char y = stk.top();
                stk.pop();
                
                if(!similar(x,y))
                { 
                    ans += x;
                    ans += y;
                }
            }
            else if(stk.size()==1 )
            {
                if(ans.size()>0 && !(similar(stk.top(),ans.back())))
                {
                    ans += stk.top();
                    stk.pop();
                }
                else if(ans.size()==0)
                {    
                    ans += stk.top();
                    stk.pop();
                }
                
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};