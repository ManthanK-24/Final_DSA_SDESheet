class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int ans = 0;
        vector<pair<int,int>> vp;
        int cnt = 1;
        bool hasZero=0;
        if(nums[0])ans = 1;
        else hasZero=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0)hasZero=1;
           if(nums[i]!=nums[i-1])
           {
               vp.push_back({nums[i-1],cnt});
               cnt = 1;
               if(i==nums.size()-1)vp.push_back({nums[i],cnt});
           }
            else
            {
                cnt++;
                if(i==nums.size()-1){
                  vp.push_back({nums[i],cnt});
                }
            }
        }
        for(int i=0;i<vp.size();i++)
        {
            //cout<<vp[i].first<<" "<<vp[i].second<<"\n";
            if(i+2<vp.size())
            {
                if(vp[i].first==1 && vp[i+1].first==0 && vp[i+2].first==1)
                {
                    if(vp[i+1].second==1)
                    ans = max(ans,vp[i].second + vp[i+2].second);
                }
            }
            if(vp[i].first==1)
                ans = max(ans,vp[i].second);
        }
       // cout<<"#\n";
        
        return hasZero?ans:ans-1;
    }
};