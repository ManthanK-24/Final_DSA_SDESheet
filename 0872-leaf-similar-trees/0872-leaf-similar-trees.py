/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
    var arr1, arr2 []int
    
    dfs(root1, &arr1)
    dfs(root2, &arr2)
    
    if len(arr1) != len(arr2) {
        return false
    }
    
    for i := 0; i < len(arr1); i++ {
        if arr1[i] != arr2[i] {
            return false
        }   
    }
    
    return true
}

func dfs(root *TreeNode, arr *[]int) {
    if root == nil {
        return 
    }
    
    if root.Left == nil && root.Right == nil {
        *arr = append(*arr, root.Val)
    }
    
    dfs(root.Left, arr)
    dfs(root.Right, arr)
}