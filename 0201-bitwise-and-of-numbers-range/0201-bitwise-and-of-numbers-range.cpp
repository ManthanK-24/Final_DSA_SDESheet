class Solution {
public:
    int getMSB(int n)
    {
        for(int i=31;i>=0;i--)
        {
           int msk = 1<<i;
            if(msk & n)
                return i;
        }
        return -1;
        
    }
    int rangeBitwiseAnd(int left, int right) {
        
        if(left==0 || right==0) return 0;
        if(left==right)return left;
        
        int lmsb = getMSB(left);
        int rmsb = getMSB(right);
        
        if(lmsb!=rmsb)return 0;
        int ans = 0;
        for(int i=rmsb;i>=0;i--)
        {
            int msk = 1<<i;
            int l = (msk&left)?1:0;
            int r = (msk&right)?1:0;
            if(l==r)
            {
                ans += r<<i;
            }
            else
                break;
            
        }
        return ans;
    }
};