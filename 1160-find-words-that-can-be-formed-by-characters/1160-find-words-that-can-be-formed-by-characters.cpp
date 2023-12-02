class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        int ans = 0;
        unordered_map<char,int> ump, tmp;
        for(int i=0;i<chars.size();i++)
        {
             ump[chars[i]]++;
        }
        for(int i=0;i<words.size();i++)
        {
            
            for(char x:words[i])tmp[x]++;
            bool flg = 1;
            for(char x:words[i])
            {
                if(ump[x]<tmp[x])
                {
                    flg=0;
                    break;
                }
            }
            tmp.clear();
            if(flg)
                ans+= words[i].size();
        }
        return ans;
    }
};