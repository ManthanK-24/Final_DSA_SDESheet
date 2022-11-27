class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int mn = INT_MAX, mx = INT_MIN;
        for(int i=0;i<pr.size();i++)
        {
            mn= min(mn,pr[i]);
            mx=max(mx,pr[i]-mn);
        }
        return max(mx,0);
    }
};