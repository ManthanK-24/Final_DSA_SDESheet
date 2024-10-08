class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vt;
        
        for(auto x:nums)vt.push_back(to_string(x));
        sort(begin(vt), end(vt), [](string& s1, string& s2){return s1+s2>s2+s1;});
        
        string res;
        for(auto x:vt)res += x;
        
        while(res[0]=='0' && res.size()>1)
            res.erase(0,1);
        return res;
    }
};