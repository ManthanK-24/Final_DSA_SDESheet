class Solution {
public:
    void solve(string s, vector<string>& res, unordered_set<string>& st, vector<string>&temp)
    {
        if(s.length() == 0){
            string str = "";
            for(auto it:temp){
                str += it + " ";
            }
            str.pop_back();
            res.push_back(str);
            return;
        }
        for(int i=0;i<s.length(); i++){
            if(st.count(s.substr(0, i+1))){
                temp.push_back(s.substr(0, i+1));
                solve(s.substr(i+1), res, st, temp);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res, temp;
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        
        solve(s, res, st, temp);
        return res;
    }
    /*void solve(int idx,string s,map<string,bool> mp,string& tmp,vector<string>& ds)
    {
        cout<<idx<<"idx "<<tmp<<"tmp\n";
        if(idx==s.size())
        {
            ds.push_back(tmp);
        }
        
        for(int i=idx;i<s.size();i++)
        {
            tmp += s[i];
            cout<<tmp<<"$tmp "<<i<<"i #\t";
            if(mp.find(tmp)!=mp.end())
            {
                tmp += " ";
                solve(i+1,s,mp,tmp,ds);
            }
           // tmp.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string> ds;
        map<string,bool> mp;
        for(auto x:wordDict)
        {
            mp[x]=1;
        }
        string tmp;
        solve(0,s,mp,tmp,ds);
        return ds;
    }*/
};