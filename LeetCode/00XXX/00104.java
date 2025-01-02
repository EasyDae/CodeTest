//https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
    int max = 0;
    public int maxDepth(TreeNode root) {
        if(root != null)
            search(root, 1);
        return max;
    }
    void search(TreeNode node, int depth){
        if(node.left == null && node.right == null){
            max = Math.max(max, depth);
            return;
        }
        if(node.left != null)
            search(node.left, depth+1);
        if(node.right != null)
            search(node.right, depth+1);
    }
}
