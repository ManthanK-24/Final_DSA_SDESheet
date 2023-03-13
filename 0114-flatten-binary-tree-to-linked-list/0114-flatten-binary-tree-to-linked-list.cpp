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
    TreeNode* helper(TreeNode* root, TreeNode* prev)
    {
        if(!root)return prev;
        prev = helper(root->right,prev);
        prev = helper(root->left,prev);
        root->right = prev;
        root->left = NULL;
      //  prev = root;
        return root;
    }
    void flatten(TreeNode* root) {
        // Brute using Auxilary Space TC:O(n) SC:O(n)
        helper(root,NULL);
    }
};