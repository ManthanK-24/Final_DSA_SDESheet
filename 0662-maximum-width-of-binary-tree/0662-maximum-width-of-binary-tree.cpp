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
    int widthOfBinaryTree(TreeNode* root) {
        
        int ans = 0;
        if(!root)return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        
        while(q.size())
        {
            int sz = q.size();
            int minidxatcurlev = q.front().second;
            int mn,mx;
            for(int i=0;i<sz;i++)
            {
                int idx =  q.front().second - minidxatcurlev+1;
                TreeNode *frnt = q.front().first;
                q.pop();
                if(i==0)mn = idx;
                if(i==sz-1)mx= idx;
                
                if(frnt->left)q.push({frnt->left,2LL*idx});
                if(frnt->right)q.push({frnt->right,2LL*idx+1});
            }
            ans = max(ans,mx-mn+1);
            
        }
        return ans;
    }
};