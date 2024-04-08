class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
       int one=0,zero=0;
        
        for(auto x:students)
        {
            if(x==1)one++;
            else
                zero++;
        }
        
        int eaters = 0;
        
        for(int i=0;i<sandwiches.size();i++)
        {
            if(sandwiches[i]==0)
            {
                
                if(zero>0)
                {
                    zero--;
                    eaters++;
                }
                else
                    break;
            
            }
            else
            {
                if(one>0)
                {
                    one--;
                    eaters++;
                }
                else
                    break;
            }
        }
        
        return students.size()-eaters;
        
    }
};