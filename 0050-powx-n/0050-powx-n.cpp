class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long nn = abs(n);
        while(nn)
        {
            if(nn%2)
            {
                ans = ans*x;
                nn--;
            }
            else
            {
                x = x*x;
                nn = nn/2;
            }
            
        }
        return n<0 ? 1/ans:ans;
    }
};