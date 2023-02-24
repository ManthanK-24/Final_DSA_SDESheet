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
    bool areSame(TreeNode* x, TreeNode* y)
    {
        if(!x and !y)return 1;
        if(x and !y)return 0;
        if(y and !x)return 0;
        
        return ((x->val==y->val) and areSame(x->left,y->right) and areSame(x->right,y->left));
    }
    bool isSymmetric(TreeNode* root) {
        return areSame(root->left,root->right);
    }
};