class Solution {
public:
    int hammingWeight(uint32_t n) {
        // Brian-Kernighan Algorithm 
        // Approach => Unset the right most bit
        int ans = 0;
        while(n>0)
        {
            n = n & n-1;
            ans += 1;
        }
        return ans;
    }
};