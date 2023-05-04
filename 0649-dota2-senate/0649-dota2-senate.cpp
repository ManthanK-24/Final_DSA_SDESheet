class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int n = senate.size();
        string d="Dire";
        string r="Radiant";
        queue<int> rq,dq;
        for(int i=0;i<senate.size();i++)
        {
            if(senate[i]=='R')rq.push(i);
            else
                dq.push(i);
        }
        while(!dq.empty() && !rq.empty())
        {
            int rf = rq.front();
            int df = dq.front();
            rq.pop();
            dq.pop();
            if(rf<df)
            {
             rf = rf + n;
                rq.push(rf);
            }
            else
            {
               df = df+n;
                dq.push(df);
            }
        }
        return (dq.size()?d:r);
    }
};