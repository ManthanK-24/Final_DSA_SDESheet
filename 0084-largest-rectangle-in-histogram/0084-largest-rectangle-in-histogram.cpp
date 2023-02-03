class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       
        stack<int> st;
        int maxArea = 0, n = heights.size();
        for(int i=0;i<=n;i++){
         while(!st.empty() && (i==n || heights[st.top()]>heights[i])){
             int ht = heights[st.top()];
             st.pop();
             int wd;
             if(st.empty()){
                 wd = i;
             }
             else
                 wd = i-st.top()-1;
             maxArea = max(maxArea,ht*wd);
         }
          st.push(i);
        }
            return maxArea;
    }
};