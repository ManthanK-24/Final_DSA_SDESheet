class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        unordered_map<int,vector<int>> ump;
        for(int i=0;i<manager.size();i++)
        {
            ump[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        int ans=0;
        q.push({headID,0});
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int head = q.front().first;
                int totTime = q.front().second;
                q.pop();
                int dur = informTime[head] + totTime;
                ans = max(ans,dur);
                for(auto it:ump[head])
                {
                    q.push({it,dur});
                }
                
            }
        }
        return ans;
    }
};