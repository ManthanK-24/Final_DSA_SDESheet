class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
       // Brute TC:O(n) SC:O(n)
       int n = nums.size();
        int zero = 0;
        int j = 0;
      //  for(int i=0;i<n;i++)if(nums[i]==0)zero++;
        
        for(int i=0;i<n;i++)    
        {
            if(nums[i]==0)
            {
                zero++;
            }
            else 
            {
                 swap(nums[i],nums[j]);
                j++;
            }
        }
        j = n-1;
        while(j>=0 && zero>0)
        {
            nums[j--] = 0;
            zero--;
        }
        
    }
};