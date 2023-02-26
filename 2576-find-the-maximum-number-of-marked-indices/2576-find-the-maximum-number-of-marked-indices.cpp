class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        
        int ans = 0, n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0, j=n/2;
        while(i<n/2 && j<n)
        {
            if(nums[i]*2<= nums[j]) ans+=2, i++,j++;
            else
                j++;
        }
        return ans;
        
    }
};