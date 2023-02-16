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
    int dfs(TreeNode* root,int& maxDpth){
        if(!root)return 0;
        int l = 1 + dfs(root->left,maxDpth);
        int r = 1 + dfs(root->right,maxDpth);
        maxDpth = max(maxDpth,max(l,r));
        return  max(l,r);
    }
    int maxDepth(TreeNode* root) {
        
        int maxDpth = 0;
        dfs(root,maxDpth);
        return maxDpth;
    }
};