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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root)return ans;
        int flg = 1;
        
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            int a = q.size();
            vector<int> tmp;
            for(int i=0;i<a;i++)
            {
                TreeNode *frnt = q.front();
                q.pop();
                tmp.push_back(frnt->val);
                if(frnt->left)q.push(frnt->left);
                if(frnt->right)q.push(frnt->right);
            }
            if(!flg)
            {
                reverse(tmp.begin(),tmp.end());
                ans.push_back(tmp);
                flg ^= 1;
            }
            else
            {
                ans.push_back(tmp);
                flg ^= 1;
            }
        
        }
        
        return ans;
    }
};