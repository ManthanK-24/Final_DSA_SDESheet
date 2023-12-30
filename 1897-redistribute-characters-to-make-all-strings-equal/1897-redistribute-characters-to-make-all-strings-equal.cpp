class Solution {
public:
    bool makeEqual(vector<string>& words)
    {
       map<char,int> mp;
        int n = words.size();
        for(auto x:words)
        {
            for(auto y:x)
            {
                mp[y]++;
            }
        }
        for(auto [x,y]:mp)
        {
            if(y%words.size())
            {
                return 0;
            }
        }
        return 1;
    }
};