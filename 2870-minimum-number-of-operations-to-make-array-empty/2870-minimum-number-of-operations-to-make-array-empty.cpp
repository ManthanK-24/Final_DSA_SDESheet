class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        map<int,int> mp;
        for(auto x:nums)mp[x]++;
        
        for(auto [key,value]:mp)
        {
           // cout<<key<<"key "<<value<<"value "<<ans<<"ans\n";
            if(value%3==0) ans+= value/3;
            else
            {
                // either val%3 will be 2
                if(value%3==2)
                {
                  ans += value/3;
                  ans += 1;
                }
                else // or 1
                {
                    // if(value%2!=0)
                    // return -1;
                    // else
                    // {
                        int tmp =value/3-1; 
                       if(tmp==-1)return tmp;
                        ans += tmp;
                        if((value-tmp*3)%2==0)
                        ans += (value-tmp*3)/2;
                        else if((value-(tmp-1)*3)%2==0)
                        {
                            ans += -1;
                            ans += (value-(tmp-1)*3)/2;
                        }
                        else
                            return -1;
                    //}
                }
            }
        //   cout<<key<<"key "<<value<<"value "<<ans<<"ans\n";
        }
     //  cout<<"#\n";
        return ans;
    }
};