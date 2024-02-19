class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return n;
        long long nn = n;
        long long ans = (nn & (nn-1));
        return ans==0;
    }
};