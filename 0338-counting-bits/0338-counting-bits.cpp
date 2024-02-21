class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1,0);
        
        // x and y=x/2 
        // noOfsetBits(x) - noOfsetBits(y) <= 1
        // if x is odd then it will have 1 extra set bit than y
        
        for(int i=1;i<=n;i++)
        {
            // ans[i] = __builtin_popcount(i);
            ans[i] = ans[i/2] + i%2;
        }
        return ans;
    }
};