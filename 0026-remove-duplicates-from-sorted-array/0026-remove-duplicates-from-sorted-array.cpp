class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        map<int,int> freq;

        for(int i=0;i<nums.size();i++)
        {
            if(freq[nums[i]]==0)
            {
                freq[nums[i]]++;
                nums[j++]=nums[i];
            }
            
        }
        return j;
    }
};