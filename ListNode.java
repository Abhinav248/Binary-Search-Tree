package main.java;

import java.util.Objects;

public class ListNode {

    private int value;
    private ListNode next;

    public ListNode() {
        // Non Parameterized Constructer
    }

    public ListNode(int value) {
        this.value = value;
    }

    public ListNode(int value, ListNode next) {
        this.value = value;
        this.next = next;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public ListNode getNext() {
        return next;
    }

    public void setNext(ListNode next) {
        this.next = next;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        ListNode oneNode = (ListNode) o;
        return getValue() == oneNode.getValue();
    }

    @Override
    public int hashCode() {
        return Objects.hash(getValue());
    }

}
