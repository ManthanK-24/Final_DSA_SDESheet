class Solution {
public:
    void merge(vector<int>& nums, vector<int>& tmp,int lft,int mid, int rgt)
    {
        int i=lft,j=mid+1,k=lft;
        while(i<=mid && j<=rgt)
        {
            if(nums[i]<=nums[j])
            {
                tmp[k++]=nums[i++];
            }
            else
            {
                tmp[k++]=nums[j++];
            }
        }
        while(i<=mid)
        {
            tmp[k++]=nums[i++];
        }
        while(j<=rgt)
        {
            tmp[k++]=nums[j++];
        }
        for(int x=lft;x<=rgt;x++)
        {
            nums[x]=tmp[x];
        }
        
    }
    void mergesort(vector<int>& nums, vector<int>& tmp,int lft, int rgt)
    {
        if(lft>=rgt)return;
        int mid = lft + (rgt-lft)/2;
        mergesort(nums,tmp,lft,mid);
        mergesort(nums,tmp,mid+1,rgt);
        merge(nums,tmp,lft,mid,rgt);
    }
    vector<int> sortArray(vector<int>& nums) {
        
        vector<int> tmp = nums;
        mergesort(nums,tmp,0,nums.size()-1);
        return nums;
    }
};