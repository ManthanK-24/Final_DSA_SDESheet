class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
     
        int ans = 0, prev = 0;
        
        for(int i=0;i<bank.size();i++)
        {
            int tmp = 0;
            for(auto x:bank[i])
            {
                if(x=='1')tmp++;
            }
            if(prev!=0)
            {
                ans += prev*tmp;
                if(tmp!=0)
                prev = tmp;
            }
            
            else
                prev = tmp;
           // cout<<i<<"idx "<<ans<<"ans "<<prev<<"prev "<<tmp<<"tmp\n";
        }
     //   cout<<"#\n";
        return ans;
    }
};