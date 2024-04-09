class Solution {
public:
    int timeRequiredToBuy(vector<int>& ar, int k) {
        
        int ans = 0;
        
        while(1)
        {
            if(ar[k]==0)break;
            
            for(int i=0;i<ar.size();i++)
            {
                if(i==k)
                {
                    if(ar[i]>0)
                    {
                        ar[i]--;
                        ans++;
                    }
                    if(ar[i]==0)break;
                }
                else
                {
                    if(ar[i]>0)
                    {
                        ar[i]--;
                        ans++;
                    }
                }
            }
            
        }
        return ans;
    }
};