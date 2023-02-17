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
    void dfs(TreeNode* root, vector<int>& ds){
        if(!root)return;
        ds.push_back(root->val);
        dfs(root->left,ds);
        dfs(root->right,ds);
    }
    int minDiffInBST(TreeNode* root) {
        int mnDiff = INT_MAX;
        vector<int> ds;
        dfs(root,ds);
        sort(ds.begin(),ds.end());
        for(int i=1;i<ds.size();i++){
            mnDiff = min(mnDiff,ds[i]-ds[i-1]);
        }
        return mnDiff;
    }
};