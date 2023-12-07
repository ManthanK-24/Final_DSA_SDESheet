class Solution {
public:
    string largestOddNumber(string num) {
        
        string ans;
        int n = num.size();
        int j=n-1;
        bool flg = 0;
        while(j>=0)
        {
            int val = num[j]-'0';
            if(val%2)
            {
                break;
            }
            j--;
        }
        if(j<0)return ans;
        for(int i=0;i<=j;i++)ans+= num[i];
        return ans;
    }
};