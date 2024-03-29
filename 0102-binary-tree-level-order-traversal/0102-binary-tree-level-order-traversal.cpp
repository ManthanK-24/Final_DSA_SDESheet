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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            int sz = q.size();
            vector<int> vtmp;
            for(int i=0;i<sz;i++)
            {
                TreeNode *frnt = q.front();
                q.pop();
                vtmp.push_back(frnt->val);
                if(frnt->left)q.push(frnt->left);
                if(frnt->right)q.push(frnt->right);
            }
            ans.push_back(vtmp);
        }
        return ans;
    }
};