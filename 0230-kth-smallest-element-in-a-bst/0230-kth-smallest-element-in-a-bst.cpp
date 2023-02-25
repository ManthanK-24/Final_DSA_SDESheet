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
    TreeNode* ksmall(TreeNode* root,int& k)
    {
        if(!root)return root;
        
        // if(root->left)
        // {
        //      cout<<"("<<root->left->val<<","<<k<<")\n";
        // }
        TreeNode* lft = ksmall(root->left,k);
        if(lft)
        { 
            return lft;
        }
        k--;
        if(k==0)return root;
        //if(root->right)
        //cout<<"("<<root->right->val<<","<<k<<")\n";
        return ksmall(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // Brute will be using SC:O(n) TC:O(n)
        //cout<<"("<<root->val<<","<<k<<")\n";
        TreeNode* tmp = ksmall(root,k);
        if(tmp)return tmp->val;
        return -1;
    }
};