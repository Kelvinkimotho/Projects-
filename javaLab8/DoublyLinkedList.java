package org.example;

public class DoublyLinkedList {
    private Node head;
    private Node tail;

    public void add(Employee employee) {
        Node newNode = new Node(employee);
        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    public void remove(int id) {
        if (head == null) {
            return;
        }
        if (head.employee.getId() == id) {
            head = head.next;
            if (head != null) {
                head.prev = null;
            }
            return;
        }
        Node current = head;
        while (current != null && current.employee.getId() != id) {
            current = current.next;
        }
        if (current != null) {
            if (current.next != null) {
                current.next.prev = current.prev;
            }
            current.prev.next = current.next;
        }
    }

    // a function that returns a boolean ,
    public boolean contains(int id) {
        Node current = head;
        while (current != null) {
            if (current.employee.getId() == id) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    private class Node {
        Employee employee;
        Node next;
        Node prev;

        Node(Employee employee) {
            this.employee = employee;
        }
    }
}




