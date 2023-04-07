class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<string> ans;
        map<char,int> minFreqOverAll;
        for(char ch='a';ch<='z';ch++)
        {
            minFreqOverAll[ch] = INT_MAX;
        }
        for(auto word:words)
        {
            map<char,int> freq;
            for(auto ch:word)
            {
                freq[ch]++;
            }
            for(char ch='a';ch<='z';ch++)
            {
                minFreqOverAll[ch] = min(minFreqOverAll[ch],freq[ch]);
            }
            
        }
        for(char ch='a';ch<='z';ch++)
            {
                while(minFreqOverAll[ch]>0)
                {
                    ans.push_back(string(1,ch));
                    minFreqOverAll[ch]--;
                }
            }
        return ans;
    }
};