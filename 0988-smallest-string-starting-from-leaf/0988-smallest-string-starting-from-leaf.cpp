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
    void dfs(TreeNode* root, string s,vector<string>&ds){
        if(!root)return;
        
        s += ('a' + root->val);
        if(!root->left && !root->right)
        {
            reverse(s.begin(),s.end());
            ds.push_back(s);
        }
        dfs(root->left,s,ds);
        dfs(root->right,s,ds);
    }
    string smallestFromLeaf(TreeNode* root) {
        
        string s;
        vector<string>ds;
        dfs(root,s,ds);
        sort(ds.begin(),ds.end());
        return ds[0];
    }
};