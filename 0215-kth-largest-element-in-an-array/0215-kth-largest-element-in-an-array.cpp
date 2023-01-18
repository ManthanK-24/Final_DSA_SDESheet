class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int ans = 0,tmp=0;
        priority_queue<int> pq;
        for(auto x:nums)
        {
            pq.push(x);
        }
        while(pq.size()>0)
        {
            ++tmp;
            if(tmp==k)
            {
                ans = pq.top();
                break;
            }
            pq.pop();
        }
        return ans;
    }
};