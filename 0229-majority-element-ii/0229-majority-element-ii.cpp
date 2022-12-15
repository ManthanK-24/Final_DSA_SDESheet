class Solution {
public:
    vector<int> majorityElement(vector<int>& ar) {
        vector<int> ans;
        int cy = 0, cz = 0, y=-1,z=-1;
        for(int i=0;i<ar.size();i++)
        {
            if(y==ar[i])cy++;
            else if(z==ar[i])cz++;
            else if(cy==0)
            {
                y = ar[i]; cy++;
            }
            else if(cz==0)
            {
                z = ar[i];
                cz++;
            }
            else
            {
                cy--;
                cz--;
            }
        }
          cy = 0, cz = 0;
         for(auto x:ar)
         {
             if(x==y)cy++;
             else if(x==z)cz++;
         }
        if(cy> ar.size()/3)ans.push_back(y);
        if(cz> ar.size()/3)ans.push_back(z);
        return ans;
    }
};