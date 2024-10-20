class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        
        int ans = 0; 
        
        for(int i=0;i<s.size();i++)
        {  
            int mx = 0;
            vector<int> cnt(27,0);
            for(int j=i;j<s.size();j++)
            {
                cnt[s[j]-'a']++;
                mx = max(mx,cnt[s[j]-'a']);
                if(mx>=k)ans++;
            }
        }
        return ans;
    }
};