class Solution {
public:
    
    vector<bool> solve(int n)
    {
         vector<bool> isPrime(n+1,1);
       // memset(isPrime,true,sizeof(isPrime));
        isPrime[0] = 0;
        isPrime[1] = 0;
        for(int i=2;i*i<=n;i++)
        {
            if(isPrime[i])
            for(int j=i*i;j<=n;j+=i)isPrime[j] = 0;
        }
        return isPrime;
    }
    vector<vector<int>> findPrimePairs(int n) {
       vector<vector<int>> ans;
        vector<bool> isPrime = solve(n);
        for(int i=2;i<=n/2;i++)
        {
            int j = n-i;
            if(isPrime[i] and isPrime[j])ans.push_back({i,j});
        }
        return ans;
    }
};