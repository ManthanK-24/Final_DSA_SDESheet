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
    vector<int> postOrderTraverse(TreeNode* root, int& ans){
        if(!root)return {INT_MAX,INT_MIN,0};
        vector<int> left = postOrderTraverse(root->left,ans);
        vector<int> right = postOrderTraverse(root->right,ans);
        
        if(!(left.size()>0
            and right.size()>0
            and root->val > left[1]
            and root->val < right[0]))
            return {};
        int sum = root->val + left[2]+right[2];
        ans = max(ans,sum);
        int mn = min(root->val,left[0]);
        int mx = max(root->val,right[1]);
        return {mn,mx,sum};
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        postOrderTraverse(root,ans);
        return ans;
    }
};