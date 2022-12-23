class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())return 0;
        int ans = 1;
        set<int> s;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        for(auto x=s.begin();x!=s.end();x++)
        {
            v.push_back(*x);
        }
        int tmp=1;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1]+1)
            {
                tmp++;
                if(i==v.size()-1)ans = max(ans,tmp);
            }
            else
            {
                ans = max(ans,tmp);
                tmp = 1;
            }
        }
        return ans;
        
    }
};