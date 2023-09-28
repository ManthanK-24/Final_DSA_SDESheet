class Solution {
public:
    void printarr(vector<int>& nums){
        cout<<"# ";
        for(auto x:nums)cout<<x<<" ";
        cout<<"\n";
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        // Brute TC:O(n) SC:O(n) Extra
        // Inplace TC:O(n) SC:O(1)
        
        int lastEvenIndex = 0;
        int i=0, n = nums.size();
        while(i<n)
        {
            if(nums[i]%2==0)
            {
               int j = i;
                while(j>lastEvenIndex && j>=1)
                {
                    swap(nums[j],nums[j-1]);
                    j--;
                }
                lastEvenIndex++;
            }
            
           // cout<<i;
           // printarr(nums);
            i++;
        }
        return nums;
        
    }
};