class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        vector<int> tmp = heights;
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<heights.size();i++)
        {
            if(heights[i]!=tmp[i])
                ans++;
        }
        return ans;
        
    }
};