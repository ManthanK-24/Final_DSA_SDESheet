
# define ll long long 

class Solution {
public:
    ll minEnd(int n, int x) 
    {
        ll ans = 0;
        ll nn = n;
        ll xx =  x;
        
        nn--;
        ll p = 0 ;
        for(ll i=0;i<63;i++)
        {
            if(xx&1LL<<i)
            {
                ans |= 1LL<<i;
            }
            else
            {
                ans |= ((nn>>p)&1LL)<<i;
                p++;
            }
        }
        return ans;
        
       
    }
};