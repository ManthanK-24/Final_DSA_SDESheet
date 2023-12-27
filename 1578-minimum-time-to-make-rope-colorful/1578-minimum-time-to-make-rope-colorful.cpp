class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
       int cost = 0;
       vector<int> vt; // neededTime
       int n = colors.size(), i=0;
        
        while(i<n)
        {
            
            char curCol = colors[i];
            int k = i+1;
            while(k<n && colors[k]==curCol)
            {
                if(k==i+1)
                {    
                  vt.push_back(neededTime[i]);
                 // cout<<i<<"kdx "<<neededTime[i]<<"neededTime ";    
                }
                vt.push_back(neededTime[k]);
                //vt.push_back(neededTime[i+1]);
              //  cout<<k<<"kdx "<<neededTime[k]<<"neededTime ";
                //cout<<i<<"i+1 "<<neededTime[i+1]<<"neededTime\n";
                k++;
            }
                
            if(vt.size()>0)
            {
               // cout<<colors[i-1]<<"$ "<<vt.size()<<"sz ";
            sort(vt.begin(),vt.end());
            int sz = vt.size();
            int j=0;
                while(j<sz-1)
                {    
                cost += vt[j];
               // cout<<cost<<"val "<<j<<"jdx\t";
                j++;
                }
                vt.clear();
             //   cout<<"$\n";
                i=k-1;
            }
          // cout<<cost<<"cost "<<i<<"idx\n";
            i++;
            
        }
     //  cout<<"#\n";
        return cost;
        
    }
};