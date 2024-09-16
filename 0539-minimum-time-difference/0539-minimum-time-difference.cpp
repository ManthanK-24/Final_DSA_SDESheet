class Solution {
public:
    int findMinDifference(vector<string>& timePoint) {
        
        int minDiff = INT_MAX;
        vector<string> tmp = timePoint;
        int cnt = 0;
        vector<string> smp; 
        for(string x:tmp)
        {
            // if(x=="00:00")cnt++;
            int h = (x[0]-'0')*10+(x[1]-'0');
            h += 24;
            string fin = to_string(h) + x[2] + x[3] + x[4];
            smp.push_back(fin);
        }
        for(auto x:smp)tmp.push_back(x);
        sort(tmp.begin(),tmp.end());
        for(int i=1;i<tmp.size();i++)
        {
            int m1 = 0, m2 = 0;
            
            
                m1 = ((tmp[i-1][0]-'0')*10 + (tmp[i-1][1]-'0'))*60;
                m1 += ((tmp[i-1][3]-'0')*10 + (tmp[i-1][4]-'0'));
                        
                m2 = ((tmp[i][0]-'0')*10 + (tmp[i][1]-'0'))*60;
                m2 += ((tmp[i][3]-'0')*10 + (tmp[i][4]-'0'));
            
             minDiff = min(minDiff, max(m2,m1)-min(m1,m2));
            //cout<<i<<"idx "<<m1<<"m1 "<<m2<<"m2\n";
        }
        return minDiff;
        
    }
};