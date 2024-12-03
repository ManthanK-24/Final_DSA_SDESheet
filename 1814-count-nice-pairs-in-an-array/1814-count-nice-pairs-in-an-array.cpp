class Solution {
public:
    int reverseNum(int n){
        if(n==0)return 0;
        string s = to_string(n);
        reverse(s.begin(),s.end());
        // 1000
        // 0001
        string ans;
        int idx = -1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='0')
            {
                idx = i;
                break;
            }
        }
        for(int i=idx;i<s.size();i++)
        {
            ans += s[i];
        }
        
        return stoi(ans);
        
    }
    int countNicePairs(vector<int>& nums) {
        
        // if nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
        int cnt = 0;
        int mod = 1e9+7;
        map<long int, long int> mpFreq;
        
        for(int i=0;i<nums.size();i++)
        {
            long int tmp = nums[i] - reverseNum(nums[i]);
            mpFreq[tmp]++;
        }
        
        for(auto [x,y]:mpFreq)
        {
            if(y>1)
            {
                long int tmp = 1LL*y*(y-1)/2;
                cnt = (cnt + tmp)%mod;
            }
        }
        return cnt;
    }
};