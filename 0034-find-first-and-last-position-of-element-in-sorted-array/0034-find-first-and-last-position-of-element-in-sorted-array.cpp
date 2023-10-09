class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        int n = nums.size();
        int i=0,j=n-1;
        int mid;
        while(i<=j)
        {
            mid = i + (j-i)/2;
            if(nums[mid]>tar)
            {
                j = mid-1;
            }
            else if(nums[mid]<tar)
            {
                i = mid+1;
            }
            else
            {
                int lft = mid;
                while(lft>=0 && nums[lft]==tar)
                {
                    lft--;
                }
                // nums[lft+1]
                int rgt = mid;
                while(rgt<n && nums[rgt]==tar)
                {
                    rgt++;
                }
                // nums[rgt-1]
                return {lft+1,rgt-1};
                
            }
            
        }
        return {-1,-1};
    }
};