class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int ansIdx = -1;
        long int sum = 0;
        for(auto x:chalk)sum += x;
      
        k = k%sum;

        if(k%sum==0)return 0;
        
        int cur = 0;
        for(int i=0;i<chalk.size();i++)
        {
            k -= chalk[i];
            if(k<0)
            {
                ansIdx=i;
                break;
            }
            else if(k==0)
            {
                ansIdx=i+1;
                if(ansIdx==chalk.size())
                    ansIdx=0;
                break;
            }
        }
        return ansIdx;
    }
};