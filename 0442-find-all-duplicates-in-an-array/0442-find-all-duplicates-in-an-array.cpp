class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // bruteforce -> TC=O(n*n) SC=O(1)
        // using map -> TC=O(n) SC=O(n)  , map TC1 vs unorder map TC2 for search,  TC1 = O(log(n)) TC2= O(n) worst case 
        // most-optimal desired -> TC=O(n) SC=O(1) 
        
        
        // as ele are from 1 to n, for element e we flip element at index e-1 to negative
        // and if e is already negative we add it to ans 
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int idx = abs(nums[i])-1;
            if(nums[idx]<0)ans.push_back(idx+1);
            else
                nums[idx] = -nums[idx];
        }
        return ans;
    }
};