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
    void dfsSwap(TreeNode* root){
        if(!root)return;
        swap(root->left,root->right);
        dfsSwap(root->left);
        dfsSwap(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfsSwap(root);
        return root;
    }
};