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
    TreeNode* Tree(vector<int>&in, int x,int y, vector<int>&po,int a,int b)
    {
        if(x>y || a>b)return NULL;
        TreeNode* root = new TreeNode(po[b]);
        int SI = x;
        while(root->val!=in[SI])SI++;
        root->left = Tree(in,x,SI-1,po,a,a+SI-x-1);
        root->right = Tree(in,SI+1,y,po,a+SI-x,b-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return Tree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};