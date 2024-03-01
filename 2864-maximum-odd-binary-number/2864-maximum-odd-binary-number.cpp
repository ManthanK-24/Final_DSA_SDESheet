class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        string ans;
        int cnt1 = 0, cnt0 = 0;
        for(auto x:s)if(x=='1')cnt1++;else cnt0++;
        
        for(int i=0;i<cnt1-1;i++)
        {
            ans+= '1';
        }
        for(int i=0;i<cnt0;i++)
        {
            ans+= '0';
        }
        ans += '1';
        return ans;
    }
};