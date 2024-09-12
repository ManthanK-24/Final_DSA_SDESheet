class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int cnt = 0;
        vector<bool> present(27,0);
        
        for(auto x:allowed)present[x-'a']=1;
        for(auto x:words)
        {
            bool flg = 1;
            for(auto y:x)
            {
                if(!present[y-'a'])
                {
                    flg = 0;
                    break;
                }
            }
            if(flg)cnt++;
        }
        return cnt;
    }
};