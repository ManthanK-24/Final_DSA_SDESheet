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
    void dfs(TreeNode* root, int dir, int cnt, int& ans){
        if(!root)return;
        
       // cout<<root->val<<"R "<<dir<<"D "<<cnt<<"C "<<ans<<"Ans\n";
        // 0 dir => L & 1 dir => R
    
        ans = max(ans,cnt);
        
        if(dir==0){
            
            if(root->right){
            
            dfs(root->right,1,cnt+1,ans);
            
           }
           if(root->left){
            dfs(root->left,0,1,ans);
           } 
            
        }
        else{
            if(root->left){
            dfs(root->left,0,cnt+1,ans);
           
           }
            if(root->right){
            dfs(root->right,1,1,ans);
           }

        }
    }
    int longestZigZag(TreeNode* root) {
        int ans=0,cnt=0,dir=-1;
        dfs(root,dir,cnt,ans);
        return ans;
    }
};