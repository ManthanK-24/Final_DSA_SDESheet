class Solution {
public:
    int minimumSubarrayLength(vector<int>& ar, int k) {
        
        int ans = INT_MAX;
        int n = ar.size();
        for(int i=0;i<n;i++)
        {
            int orVal = 0;
            for(int j=i;j<n;j++)
            {
                orVal = orVal | ar[j];
                if(orVal>=k)
                {
                    ans = min(ans,j-i+1);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};