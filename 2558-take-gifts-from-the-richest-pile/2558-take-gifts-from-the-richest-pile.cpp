class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        long long ans = 0;
        sort(gifts.begin(),gifts.end());
        int n = gifts.size();
        vector<int> tmpDS = gifts; 
        for(int i=0;i<k;i++)
        {
            tmpDS[n-1] = sqrt(tmpDS[n-1]);
            sort(tmpDS.begin(),tmpDS.end());
        }
        for(int i=0;i<n;i++)
        {
            ans += 1LL*tmpDS[i];
        }
        return ans;
    }
};