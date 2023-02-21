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
    int ans;
    int getMaxGain(TreeNode* root)
    {
        if(!root)return 0;
        int leftGain = max(getMaxGain(root->left),0);
        int rightGain = max(getMaxGain(root->right),0);
        int cur = root->val + leftGain + rightGain;
        ans = max(ans,cur);
        return (root->val+max(leftGain,rightGain));
        
    }
    int maxPathSum(TreeNode* root) {
        
        ans = INT_MIN;
        getMaxGain(root);
        return ans;
    }
};