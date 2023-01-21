class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        nums.resize(2*n);
        vector<int> res(n,-1);
        stack<int> st;
        for(int i=n;i<2*n;i++)nums[i]=nums[i-n];
        for(int i=0;i<2*n;i++)
        {
            while(st.size() && nums[i] > nums[st.top()])
            {
                if(st.top()>=n)
                {
                    st.top() -= n;
                }
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};