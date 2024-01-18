class Solution {
public:
    
    int climbStairs(int n) {
        
        vector<int> cnt(n+2,0);
        cnt[1] = 1;
        cnt[2] = 2;
        
        for(int i=3;i>2 && i<=n  ;i++)
        {
            cnt[i] = cnt[i-1]+cnt[i-2];
        }
        return cnt[n];
    }
};