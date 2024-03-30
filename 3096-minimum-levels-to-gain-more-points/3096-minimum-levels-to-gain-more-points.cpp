class Solution {
public:
    int minimumLevels(vector<int>& ar) {
        
//         if(ar.size()==2)
//         {
//             if(ar[0]==1 && ar[1]==1)
//                 return -1;
            
//         }
        int ones = 0,zero=0;
        int a = 0, b = 0; 
        
        for(auto x:ar)
        {
            if(x==0)zero++;
            else ones++;
        }
        for(int i=0;i<ar.size();i++)
        {
            // a plays till ith 
            
            if(ar[i]==1)
            {
                a++;
                ones--;
            }
            else
            {
                a--;
                zero--;
            }
            b = ones-zero;
            if(a>b && i!=ar.size()-1)
                return i+1;
        }
        return -1;
    }
};