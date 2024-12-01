class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
     
        map<int,int> mp;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        
        for(int i=0;i<arr.size();i++)
        {
            int x = 2*arr[i];
            if(x==0)
            {
                if(mp[x]>1)return 1;
            }
            else if(mp[x]>=1)return 1;
        }
        return 0;
    }
};