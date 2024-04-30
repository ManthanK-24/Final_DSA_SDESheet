#define ll long long
class Solution {
public:
    long long wonderfulSubstrings(string word) 
    {
       ll ans = 0;
        ll mask = 0;
        map<ll,ll> cnt;
        cnt[0] = 1;
        for(auto ch:word)
        {
            int idx = ch-'a';
            mask ^= (1<<idx);
            ans += cnt[mask];
            
            for(int i=0;i<10;i++)
            {
                int lookUp = mask^(1<<i);
                ans += cnt[lookUp];
            }
            cnt[mask]++;
            
        }
        return ans;
    }
};