class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        int ans = 0;
        map<string, int> mp1,mp2;
        
        for(int i=0;i<arr1.size();i++)
        {
            string x = to_string(arr1[i]);
            int j = 0;
            string y;
            while(j<x.size())
            {
                y += x[j];
                j++;
                mp1[y]++;
            }
        }
        for(int i=0;i<arr2.size();i++)
        {
            string x = to_string(arr2[i]);
            int j = 0;
            string y;
            while(j<x.size())
            {
                y += x[j];
                j++;
                mp2[y]++;
            }
        }
        for(auto& [x,y]:mp1)
        {
            
            // cout<<x<<"# "<<y<<"$ ";
            int z = x.size();
            if(y>0 && mp2[x]>0)
            ans = max(ans,z);
           // cout<<ans<<"ans\n";
        }
      //  cout<<"#\n";
        return ans;
    }
};