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
    bool dfs_childDeleted(TreeNode* root,int tar){
        if(!root)return true;
        
        if(!root->left && !root->right){
            return(root->val==tar);
        }
        bool l = dfs_childDeleted(root->left,tar);
        bool r = dfs_childDeleted(root->right,tar);
        
         if(l && root->left)
             {
                 root->left = NULL;
             }
             if(r && root->right)
             {
                 root->right = NULL;
             }
        
        return(root->val==tar && l && r);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs_childDeleted(root,target);
        if(root->val==target)
        {
            if(!root->left && !root->right)return NULL;
        }
        return root;
    }
};