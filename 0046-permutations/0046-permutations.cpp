class Solution {
public:
    void findAllPermutations(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& ans, map<int,int>& vis)
    {
        if(tmp.size()==nums.size()){
            ans.push_back(tmp);
            return;
        }
       
        for(int i=0;i<nums.size();i++)
        {
            if(vis[nums[i]])continue;
            tmp.push_back(nums[i]);
            vis[nums[i]]=1;
            findAllPermutations(nums,tmp,ans,vis);
            tmp.pop_back();
            vis[nums[i]]=0;
        }
        
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        map<int,int> vis;
        vector<int> tmp;
        findAllPermutations(nums,tmp,ans,vis);
        return ans;
    }
};