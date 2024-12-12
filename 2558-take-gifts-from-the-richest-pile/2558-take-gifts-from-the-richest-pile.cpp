class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(int x:gifts)pq.push(x);
        
        while(k--)
        {
            int t = pq.top();
            pq.pop();
            pq.push(sqrt(t));
        }
        while(pq.size()>0)
        {
            ans += 1LL*pq.top();
            pq.pop();
        }
        return ans;
    }
};