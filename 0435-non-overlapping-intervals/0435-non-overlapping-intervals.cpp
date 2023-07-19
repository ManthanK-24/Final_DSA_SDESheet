class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> vt;
        vt.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(vt.back()[1]>intervals[i][0])
            {
                ans++;
                if(vt.back()[1]>intervals[i][1])vt.back() = intervals[i];
            }
            else
                vt.push_back(intervals[i]);
        }
        return ans;
    }
};