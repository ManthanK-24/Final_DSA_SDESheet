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
            if(vis[i])continue;
            tmp.push_back(nums[i]);
            vis[i]=1;
            findAllPermutations(nums,tmp,ans,vis);
            tmp.pop_back();
            vis[i]=0;
        }
        
        
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        map<int,int> vis;
        vector<int> tmp;
        findAllPermutations(nums,tmp,ans,vis);
        set<vector<int>> s;
        for(auto x:ans)s.insert(x);
        ans.clear();
        for(auto x:s)ans.push_back(x);
        return ans;
    }
};