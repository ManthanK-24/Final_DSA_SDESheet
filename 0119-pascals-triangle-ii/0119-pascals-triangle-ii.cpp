class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        
        vector<int> cur,prev;
        for(int i=0;i<=rowIndex;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(i>1)
                {
                    if(j==0 || i==j)
                        cur.push_back(1);
                    else
                        cur.push_back(prev[j]+prev[j-1]);
                }
                else
                {
                    
                    cur.push_back(1); 
                    
                }
            }
            prev = cur;
            cur.clear();
        }
        return prev;
        
    }
};