package main.java;

import java.util.*;

public class MyBinaryTree {

    public static void main(String[] args) {
        TreeNode root = null;
        root = buildTree(root);
        System.out.print("Inorder Tree Traversal: ");
        recursiveInorder(root);
        System.out.println();
        System.out.print("Preorder Tree Traversal: ");
        recursivePreorder(root);
        System.out.println();
        System.out.print("Postorder Tree Traversal: ");
        recursivePostorder(root);
    }

    public static TreeNode buildTree(TreeNode root) {
        if ( root == null ) {
            root = new TreeNode(1);
        }
        root.setLeft(new TreeNode(2));
        root.setRight(new TreeNode(3));
        root.getLeft().setLeft(new TreeNode(4));
        root.getLeft().setRight(new TreeNode(5));
        root.getRight().setLeft(new TreeNode(6));
        root.getRight().setRight(new TreeNode(7));
        return root;
    }

    public static void recursiveInorder(TreeNode root){
        if(root != null) {
            recursiveInorder(root.getLeft());
            System.out.print(root.getVal() + " ");
            recursiveInorder(root.getRight());
        }
    }

    public static void recursivePreorder(TreeNode root){
        if(root != null) {
            recursivePreorder(root.getLeft());
            recursivePreorder(root.getRight());
            System.out.print(root.getVal() + " ");
        }
    }

    public static void recursivePostorder(TreeNode root){
        if(root != null) {
            System.out.print(root.getVal() + " ");
            recursivePostorder(root.getLeft());
            recursivePostorder(root.getRight());
        }
    }

    public static List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> l = new ArrayList<>();
        Stack<TreeNode> s = new Stack<>();
        if(root == null){
            return l;
        }
        while(true) {
            if (root != null) {
                s.push(root);
                root=root.getLeft();
            } else {
                if (s.isEmpty())
                    break;
                else {
                    root = s.pop();
                    l.add(root.getVal());
                    root=root.getRight();
                }
            }
        }
        return l;
    }

    public static List<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> l = new ArrayList<>();
        Stack<TreeNode> s = new Stack<>();
        if(root == null){
            return l;
        }
        s.push(root);
        while(!s.isEmpty()){
            TreeNode curr = s.pop();
            l.add(curr.getVal());
            if(curr.getRight() != null)
                s.push(curr.getRight());
            if(curr.getLeft() != null)
                s.push(curr.getLeft());
        }
        return l;
    }

    public static List<Integer> postorderTraversal(TreeNode root) {
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        ArrayList<Integer> l = new ArrayList<>();
        if (root == null)
            return l;
        s1.push(root);
        while(!s1.isEmpty()) {
            TreeNode curr = s1.pop();
            s2.push(curr);
            if(curr.getLeft() != null)
                s1.push(curr.getLeft());
            if(curr.getRight() != null)
                s1.push(curr.getRight());
        }
        while(!s2.isEmpty())
            l.add(s2.pop().getVal());
        return l;
    }

    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> l = new ArrayList<>();
        List<Integer> i = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if (root == null)
            return l;
        q.add(root);
        q.add(null);
        while (true) {
            TreeNode curr = q.remove();
            if(curr==null) {
                l.add(new ArrayList<>(i)); // could also write own function to clone list
                // l.add(0, new ArrayList<>(i)); // For bottom-up level order traversal
                i.clear();
                if(q.isEmpty())
                    break;
                else
                    q.add(null);
            } else {
                i.add(curr.getVal());
                if(curr.getLeft()!=null)
                    q.add(curr.getLeft());
                if(curr.getRight()!=null)
                    q.add(curr.getRight());
            }
        }
        return l;
    }

    public static List<Integer> rightSideView(TreeNode root) {
        ArrayList<Integer> l = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if(root==null)
            return l;
        q.add(root);
        q.add(null);
        while(true) {
            TreeNode curr = q.remove();
            if(curr==null){
                if(q.isEmpty())
                    break;
                else
                    q.add(null);
            } else {
                if(q.element()==null) {
                    l.add(curr.getVal());
                }
                if(curr.getLeft()!=null)
                    q.add(curr.getLeft());
                if(curr.getRight()!=null)
                    q.add(curr.getRight());
            }
        }
        return l;
    }

    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        int res = 0;
        TreeNode prev=null;
        q.add(root);
        q.add(null);
        while(true){
            TreeNode curr = q.remove();
            if(curr==null){
                if(q.isEmpty())
                    break;
                else
                    q.add(null);
            }
            else {
                if(prev==null)
                    res=curr.getVal();
                if(curr.getLeft()!=null)
                    q.add(curr.getLeft());
                if(curr.getRight()!=null)
                    q.add(curr.getRight());
            }
            prev=curr;
        }
        return res;
    }

    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> l = new ArrayList<>();
        if(root == null)
            return l;
        List<Integer> i = new ArrayList<>();
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        s1.push(root);
        while (!s1.isEmpty() || !s2.isEmpty()) {
            while (!s1.isEmpty()) {
                TreeNode curr = s1.pop();
                if(curr.getLeft()!=null)
                    s2.push(curr.getLeft());
                if(curr.getRight()!=null)
                    s2.push(curr.getRight());
                i.add(curr.getVal());
            }
            if(!i.isEmpty())
                l.add(new ArrayList<>(i));
                // l.add(0, new ArrayList<>(i)); // For bottom-up zigzag traversal
            i.clear();
            while (!s2.isEmpty()) {
                TreeNode curr = s2.pop();
                if(curr.getRight()!=null)
                    s1.push(curr.getRight());
                if(curr.getLeft()!=null)
                    s1.push(curr.getLeft());
                i.add(curr.getVal());
            }
            if(!i.isEmpty())
                l.add(new ArrayList<>(i));
                // l.add(0, new ArrayList<>(i)); // For bottom-up zigzag traversal
            i.clear();
        }
        return l;
    }

}
