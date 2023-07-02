class Solution {
public:
    int longestAlternatingSubarray(vector<int>& ar, int thr) {
        int ans = 0 ;
        int flg,cnt;
        for(int l=0;l<ar.size();l++)
        {
            if(ar[l]%2==0 && ar[l]<=thr)
            {
                flg = 1;
                cnt = 0;
                for(int r=l;r<ar.size();r++)
                {
                    if(ar[r]%2!=flg && ar[r]<= thr)
                    {
                        flg = flg ^ 1;
                        cnt++;
                    }
                    else
                        break;
                } 
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};