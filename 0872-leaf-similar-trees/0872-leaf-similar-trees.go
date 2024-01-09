/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
     public void dfs(TreeNode root, ArrayList<Integer> al )
     {
         if(root==null)return;
             
          if(root.left==null && root.right == null)
          {
              al.add(root.val);
          }
         dfs(root.left,al);
         dfs(root.right,al);
         
         
     }
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayList<Integer> al1= new ArrayList<Integer>();
         ArrayList<Integer> al2 = new ArrayList<Integer>();
        dfs(root1,al1);
        dfs(root2,al2);
       // boolean ans = al1==al2;
       // System.out.println(al1 + "al1" +al2 + "al2");
        return al1.equals(al2);
    }
}