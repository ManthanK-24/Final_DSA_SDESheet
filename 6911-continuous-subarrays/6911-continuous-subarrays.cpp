class Solution {
public:
    long long continuousSubarrays(vector<int>& ar) {
        
        long long ans = 1;
        int mn = ar[0],mx = ar[0];
        int left = 0;
        for(int i=1;i<ar.size();i++)
        {
            mn = min(ar[i],mn);
            mx = max(ar[i],mx);
            if(mx-mn>2)
            {
               int right = i;
                mn = ar[i];
                mx = ar[i];
               while(right>=0 && abs(ar[i]-ar[right])<=2 )
               {
                   mn=min(mn,ar[right]);
                   mx=max(mx,ar[right]);
                   right--;
                   
               }
                if(abs(ar[right]-ar[i])>2) right++;
               left = right;
                
               ans += (i-left+1);
                     
            }
            else
            {
                ans += (i-left+1);
            }
           // cout<<i<<"idx "<<left<<"lft "<<mn<<"mn "<<mx<<"mx "<<ans<<"ans\t";
      }
       // cout<<"\n";
        return ans;
    }
};