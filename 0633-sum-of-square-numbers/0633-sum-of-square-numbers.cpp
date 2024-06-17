class Solution {
public:
    bool judgeSquareSum(int c) {
        
        long left = 0, right = (long)sqrt(c);
        while(left<=right)
        {
            long cur = left*left+right*right;
            if(cur<c)
            {
                left++;
            }
            else if(cur>c)
            {
                right--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};