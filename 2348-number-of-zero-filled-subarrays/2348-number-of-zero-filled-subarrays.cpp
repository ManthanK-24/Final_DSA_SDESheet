class Solution {
public:
    long long zeroFilledSubarray(vector<int>& ar) {
        
        long long ans = 0;
        int cnt=0;
        for(int i=0;i<ar.size();i++)
        {
            if(ar[i]==0)
            {
                cnt++;
                if(i==ar.size()-1)
                    ans += ((long long) cnt*(cnt+1))/2;
            }
            else
            {
                ans += ((long long) cnt*(cnt+1))/2;
                cnt =0;
            }
            
        }
        return ans;
    }
};