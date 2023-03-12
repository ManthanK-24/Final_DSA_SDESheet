class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
     
        int ans = 0;
        for(int t=1;t<=2000;t++)
        {
            bool chosen = false;
            for(auto &x:tasks )
            {
                if(x[2]+t>x[1] and x[1]>=t and x[0]<=t)chosen = true;
            }
            ans += chosen;
            if(chosen)
            {
                for(auto &x:tasks )
               {
                 if(x[2]>=0 and x[1]>=t and x[0]<=t)x[2]--;
               }
                
            }
            
        }
        return ans;
    }
};