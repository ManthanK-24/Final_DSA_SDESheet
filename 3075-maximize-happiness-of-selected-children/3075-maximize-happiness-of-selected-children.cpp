class Solution {
public:
    long long maximumHappinessSum(vector<int>& ar, int k) {
        
        long long ans = 0;
        sort(ar.begin(),ar.end());
        reverse(ar.begin(),ar.end());
        
        int tmp = 0;
        
        for(int i=0;i<ar.size();i++)
        {
            // if(tmp>0)
                ar[i] -= tmp;
            if(ar[i]<=0 || tmp==k)break;
            ans += ar[i];
            
            tmp += 1;
           // cout<<i<<"i "<<ans<<"ans "<<ar[i]<<"ar[i] "<<tmp<<"tmp\n";
        }
        return ans;
    }
};