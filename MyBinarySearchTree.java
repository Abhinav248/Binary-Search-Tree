package main.java;

import java.util.*;

public class MyBinarySearchTree {

    public static void main(String[] args) {
        TreeNode root = null;
        root = buildTree(root);
        System.out.print("Inorder Tree Traversal: ");
        recursiveInorder(root);
    }

    public static TreeNode buildTree(TreeNode root) {
        if ( root == null ) {
            root = insertNode(null,4);
        }
        insertNode(root,2);
        insertNode(root,3);
        insertNode(root,1);
        insertNode(root,6);
        insertNode(root,5);
        insertNode(root,7);
        return root;
    }

    public static void recursiveInorder(TreeNode root){
        if(root != null) {
            recursiveInorder(root.getLeft());
            System.out.print(root.getVal() + " ");
            recursiveInorder(root.getRight());
        }
    }

    // Specific to BST
    public static TreeNode insertNode(TreeNode root, int v){
        TreeNode newNode = new TreeNode(v);
        if(root==null)
            return newNode;
        //if(v==root.getVal()) // not required as already
        //    return root;     // returning root at end
        else if(v<root.getVal())
            root.setLeft(insertNode(root.getLeft(), v));
        else
            root.setRight(insertNode(root.getRight(), v));
        return root;
    }

    // Specific to BST
    public static TreeNode searchValue(TreeNode root, int keyValue){
        if(root==null)
            return null;
        if(root.getVal()==keyValue)
            return root;
        else if(root.getVal()>keyValue)
            return searchValue(root.getLeft(), keyValue);
        else
            return searchValue(root.getRight(), keyValue);
    }

    public static boolean isValidBST(TreeNode root) {
        if(isBST(root, Long.MIN_VALUE, Long.MAX_VALUE))
            return true;
        return false;
    }

    public static boolean isBST(TreeNode root, long min, long max) {
        if(root==null)
            return true;
        if(root.getVal()<=min || root.getVal()>=max)
            return false;
        return isBST(root.getLeft(), min, root.getVal()) &&
                isBST(root.getRight(), root.getVal(), max);
    }

    /* Assumptions for LCA Problem:
       All Node.val are unique.
       p!=q
       p and q will exist in the BST. */

    // Specific to BST
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null || root.getVal()==p.getVal() || root.getVal()==q.getVal() ||
                (root.getVal()>Math.min(p.getVal(),q.getVal()) && root.getVal()<Math.max(p.getVal(),q.getVal())))
            return root;
        return (root.getVal()>Math.max(p.getVal(),q.getVal()))?lowestCommonAncestor(root.getLeft(), p, q):
                lowestCommonAncestor(root.getRight(), p, q);
    }

    // Specific to BST
    public TreeNode iterativeLCA(TreeNode root, TreeNode p, TreeNode q) {
        while(root!=null) {
            if(root.getVal()>p.getVal() && root.getVal()>q.getVal())
                root=root.getLeft();
            else if(root.getVal()<p.getVal() && root.getVal()<q.getVal())
                root=root.getRight();
            else break;
        }
        return root;
    }

}

