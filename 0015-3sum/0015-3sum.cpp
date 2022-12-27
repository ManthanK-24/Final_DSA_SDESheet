class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            int front = i+1;
            int back = nums.size()-1;
            int sum = 0 - nums[i];
            
            while(front<back)
            {
                if(nums[front]+nums[back]>sum)
                {
                    back--;
                }
                else if(nums[front]+nums[back]<sum)
                {
                    front++;
                }
                else
                {
                    vector<int>tmp;
                    tmp.push_back(nums[i]); 
                    tmp.push_back(nums[front]);
                    tmp.push_back(nums[back]);
                    res.push_back(tmp);
                    
                    while(front < back && nums[front]== tmp[1])front++;
                    while(front < back && nums[back]==tmp[2])back--;
                    
                }
                while(i+1<nums.size() && nums[i]==nums[i+1])i++;
            }
        }
        return res;
    }
};