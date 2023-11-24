class Solution {
public:
    int maxCoins(vector<int>& piles) {
     
        int ans = 0;
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int i=0, j = n-2;
        
        while(i<=j)
        {
            ans += piles[j];
            j -= 2;
            i += 1;
        }
        return ans;
    }
};