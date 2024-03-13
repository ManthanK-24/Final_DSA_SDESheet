class Solution {
public:
    int pivotInteger(int n) {
        
        int totSum = (n*(n+1))/2;
        int sum=0;
        int t = 1;
        while(t<=n)
        {
            sum += t;
            if(sum==totSum+t-sum)
            {
                return t;
            }
            t++;
        }
        return -1;
    }
};