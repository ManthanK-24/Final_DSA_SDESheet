class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> res;
        map<int,int> mp;
        for(auto x:nums)mp[x]++;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push(make_pair(it->second,it->first));
            if(pq.size() > mp.size()-k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
        
    }
};