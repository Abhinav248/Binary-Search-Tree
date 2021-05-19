package main.java;

public class MyLinkedList {

    public static void main(String[] args) {
        ListNode head = null;
        head=addNode(head, 1);
        addNode(head, 2);
        addNode(head, 3);
        addNode(head, 4);
        addNode(head, 5);
        printList(head);
        head = reverse1(head);
        printList(head);
        head = reverse2(head);
        printList(head);
    }

    public static void printList(ListNode head) {
        while(head!=null){
            System.out.println(head.getValue());
            head=head.getNext();
        }
    }

    public static ListNode addNode(ListNode head, int v) {
        ListNode newNode = new ListNode(v, null);
        if(head == null){
            return newNode;
        }
        ListNode temp = head;
        while(temp.getNext()!=null) {
            temp=temp.getNext();
        }
        temp.setNext(newNode);
        return head;
    }

    public static ListNode reverse1(ListNode head) {
        if (head == null || head.getNext() == null) {
            return head;
        }
        ListNode new_head = reverse1(head.getNext());
        head.getNext().setNext(head);
        head.setNext(null);
        return new_head;
    }

    public static ListNode reverse2(ListNode head) {
        if (head == null || head.getNext() == null) {
            return head;
        }
        ListNode rootNext = head.getNext();
        head.setNext(null);
        ListNode revRoot = reverse2(rootNext);
        rootNext.setNext(head);
        return revRoot;
    }

    public static ListNode findIntersecrion(ListNode node1, ListNode node2) {
        return null;
    }

}
