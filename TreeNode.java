package main.java;

import java.util.Objects;

public class TreeNode {
    private int val;
    private TreeNode left;
    private TreeNode right;

    public TreeNode() {
        //Non Parameterized Constructer
    }

    public TreeNode(int val) {
        this.val = val;
    }

    public TreeNode(TreeNode node) {
        this.left = left;
    }

    public TreeNode(int val, TreeNode node) {
        this.val = val;
        this.left = left;
    }

    public TreeNode(TreeNode left, TreeNode right) {
        this.left = left;
        this.right = right;
    }

    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }

    public int getVal() {
        return val;
    }

    public void setVal(int val) {
        this.val = val;
    }

    public TreeNode getLeft() {
        return left;
    }

    public void setLeft(TreeNode left) {
        this.left = left;
    }

    public TreeNode getRight() {
        return right;
    }

    public void setRight(TreeNode right) {
        this.right = right;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TreeNode treeNode = (TreeNode) o;
        return getVal() == treeNode.getVal();
    }

    @Override
    public int hashCode() {
        return Objects.hash(getVal());
    }

}
