/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root)return ans;
        map<int,vector<pair<int,int>>> mv;
        queue<pair<TreeNode*,vector<int>>> q;
        q.push({root,{0,0}});
        while(q.size())
        {
            int a = q.size();
            for(int i=0;i<a;i++)
            {    
            int x = q.front().second[0];
            int y = q.front().second[1];
            TreeNode *it = q.front().first;
             mv[y].push_back({x,it->val});
            q.pop();
            if(it->left)q.push({it->left,{x+1,y-1}});
            if(it->right)q.push({it->right,{x+1,y+1}});
            }
            
        }
        vector<int> v;
        for(auto a:mv)
        {  // cout<<a.first<<"#\n";
           // for(auto ele:a.second)cout<<ele<<" ";
         //cout<<"\n";
            vector<pair<int,int>>tmp = a.second;
            sort(tmp.begin(),tmp.end());
            v.clear();
            for(auto [s,t]:tmp)v.push_back(t);
            ans.push_back(v);
            
        }
        //cout<<endl;
        return ans;
    }
};