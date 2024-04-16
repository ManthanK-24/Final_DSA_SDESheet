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
    void  dfs(TreeNode* root, int val, int depth, int curDepth)
    {
        if(!root)return;
        
       
        
        TreeNode* lft = root->left;
        TreeNode* rgt = root->right;
        
        if(curDepth==depth-1)
        {
            TreeNode* tmpL = new TreeNode(val);
            TreeNode* tmpR = new TreeNode(val);
            
            if(root->left)
            {
                root->left = tmpL;
                tmpL->left = lft;
            }
            else
            {
                root->left = tmpL;
            }
            if(root->right)
            {
                root->right = tmpR;
                tmpR->right = rgt;
            }
            else
            {
                root->right = tmpR;
            }
            if(!lft && !rgt)
            {
                root->left = tmpL;
                root->right = tmpR;
            }
        }
        dfs(root->left,val,depth,curDepth+1);
        dfs(root->right,val,depth,curDepth+1);
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
         if(depth==1)
        {
            TreeNode* node = new TreeNode(val);
            TreeNode* tmp = root;
            node->left = tmp;
            node -> right = NULL; 
            return node;
        }
        dfs(root, val, depth, 1);
        return root;
    }
};