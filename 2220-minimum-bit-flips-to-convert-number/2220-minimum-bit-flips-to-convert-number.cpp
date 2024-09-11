class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int cnt = 0;
        for(int i=30;i>=0;i--)
        {
            bool msk1 = ((1<<i)&start);
            bool msk2 = ((1<<i)&goal);
            if(msk1!=msk2)cnt++;
        }
        return cnt;
    }
};