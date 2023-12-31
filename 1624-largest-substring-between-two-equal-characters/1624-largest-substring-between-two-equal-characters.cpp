class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        int ans = 0;
        bool flag = 0; 
        vector<int> idx(26,-1);
        
        for(int i=0;i<s.size();i++)
        {
            if(idx[s[i]-'a']==-1)
            {
                idx[s[i]-'a']=i;
            }
            else
            {
                flag = 1;
                ans = max(ans,i-idx[s[i]-'a']-1);
            }
           // cout<<i<<"i "<<ans<<"#\t";
        }
        //cout<<"\n";
       
        return flag==1? ans:-1;
    }
};