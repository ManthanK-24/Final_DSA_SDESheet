class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s1,s2;
        for(auto x:word1)s1 += x;
        for(auto y:word2)s2 += y;
        return s1==s2;
    }
};