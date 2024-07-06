class Solution {
public:
    int passThePillow(int n, int time) {
        
        int ans = 1;
        bool dir = 1; // 1 for right & 0 for left
        while(time>0)
        {
            if(dir==1)
            {
                if(ans<n)
                {
                    ans++;
                }
                else
                {
                    dir=0;
                    ans=n-1;
                }
            }
            else
            {
                if(ans>1)
                {
                    ans--;
                }
                else
                {
                    dir=1;
                    ans=2;
                }
            }
            time--;
        }
        return ans;
    }
};