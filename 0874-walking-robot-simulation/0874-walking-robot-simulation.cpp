class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int ans = 0;
        map<vector<int>,bool> mp;
        
        for(auto vt:obstacles){
            mp[vt]=1;
        }
        int x=0, y=0;
        
        char dir = 'n';
        
        for(int i=0;i<commands.size();i++)
        {
            
            if(commands[i]==-2)
            {
                if(dir=='n')dir='w';
                else if(dir=='e')dir='n';
                else if(dir=='s')dir='e';
                else if(dir=='w')dir='s';
            }
            else if(commands[i]==-1)
            {
                if(dir=='n')dir='e';
                else if(dir=='e')dir='s';
                else if(dir=='s')dir='w';
                else if(dir=='w')dir='n';
            }
            else
            {
                int d = commands[i];
                
                if(dir=='n')
                {
                    
                   while(d>0)
                   {
                       y++;
                       if(mp[{x,y}])
                       {
                           y--;
                           break;
                       }
                       d--;
                   }
                    
                }
                else if(dir=='w')
                {
                    while(d>0)
                    {
                        x--;
                        if(mp[{x,y}])
                        {
                            x++;
                            break;
                        }
                        d--;
                    }
                }
                else if(dir=='s')
                {
                    while(d>0)
                    {
                        y--;
                        if(mp[{x,y}])
                        {
                            y++;
                            break;
                        }
                        d--;
                    }
                }
                else if(dir=='e')
                {
                    while(d>0)
                    {
                        x++;
                        if(mp[{x,y}])
                        {
                            x--;
                            break;
                        }
                        d--;
                    }
                }
                int val = abs(x)*abs(x)+abs(y)*abs(y);
                ans = max(ans, val);
                
            }
           // cout<<i<<"i "<<commands[i]<<"comm[i] "<<x<<"x "<<y<<"y "<<ans<<"ans\n";
        }
        return ans;
    }
};