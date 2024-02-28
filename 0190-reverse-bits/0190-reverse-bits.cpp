class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t ans = 0, msk = 1<<31;
        while(n!=0)
        {
            if(n&1) ans += msk;
            n >>= 1;
            msk >>= 1;
        }
        return ans;
    }
};