class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        //vector<int> ans(n,0);
        //for(int i=0;i<n;i++)ans[i] = i+1;
        
        //sort(ans.begin(),ans.end(),
        //     [](int& a, int& b){return to_string(a)<to_string(b);});
        //return ans;
        
        vector<int> res;
        helper(1,n,res);
        return res;
    }
    void helper(int target, int n, vector<int>& res)
    {
        if(target>n)return;
        res.push_back(target);
        helper(target*10,n,res);
        if(target%10!=9)helper(target+1,n,res);
    }
};