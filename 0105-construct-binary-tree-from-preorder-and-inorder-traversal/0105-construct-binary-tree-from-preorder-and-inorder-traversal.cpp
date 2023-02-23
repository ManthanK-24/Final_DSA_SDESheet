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
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
        return helper(0,0,inOrder.size()-1,preOrder,inOrder);
    }
    TreeNode* helper(int preStart,int inStart, int inEnd ,vector<int>& preOrder, vector<int>& inOrder)
    {
        if(preStart>preOrder.size()-1 || inStart > inEnd)return NULL;
        
        TreeNode* root = new TreeNode(preOrder[preStart]);
        int inIndex = 0;
        for(int i=inStart;i<=inEnd;i++)
        {
            if(inOrder[i]==root->val)
            {
                inIndex = i;
            }
        }
        root->left = helper(preStart+1,inStart,inIndex-1,preOrder,inOrder);
     
        root->right = helper(preStart + inIndex-inStart+1,
                             inIndex+1,inEnd,preOrder,inOrder);
        return root;
    }
};