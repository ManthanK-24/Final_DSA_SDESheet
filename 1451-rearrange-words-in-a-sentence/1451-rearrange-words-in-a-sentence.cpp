class Solution {
public:
    string arrangeWords(string text) {
        
        string ans,tmp;
        vector<pair<vector<int>,string>> vs;
        
        for(int i=0;i<text.size();i++)
        {
            if((text[i]>='a' and text[i]<='z') or 
               (text[i]>='A' and text[i]<='Z') )
            {
                tmp += text[i];
                int sz = tmp.size();
                vector<int> v = {sz,i};
                if(i==text.size()-1)
                    vs.push_back({v,tmp});
            }
            else
            {
                int sz = tmp.size();
                vector<int> v = {sz,i};
                vs.push_back({v,tmp});
                tmp.clear();
            }
                
        }
        sort(vs.begin(),vs.end());
        for(int i=0;i<vs.size();i++)
        {
            
                string x = vs[i].second; 
                if(i==0)
                {
                    if(islower(x[0]))
                    {
                        x[0] = toupper(x[0]);
                    }
                }
                else
                {
                    if(isupper(x[0]))
                    {
                        x[0] = tolower(x[0]);
                    }
                }
                ans += x;
            
            if(i<vs.size()-1)
            ans += ' ';
            
            
        }
        return ans;
    }
};