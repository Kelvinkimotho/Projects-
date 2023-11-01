package org.example;

public class SortedLinkedList {
    private Node head;

    // A function to add an employee as a node to the list
    public void add(Employee employee) {
        Node newNode = new Node(employee);
        if (head == null || head.employee.getId() > employee.getId()) {
            newNode.next = head;
            head = newNode;
        } else {
            Node current = head;
            while (current.next != null && current.next.employee.getId() < employee.getId()) {
                current = current.next;
            }
            newNode.next = current.next;
            current.next = newNode;
        }
    }

    // A function to remove a node from a list
    public void remove(int id) {
        if (head == null) {
            return;
        }
        if (head.employee.getId() == id) {
            head = head.next;
            return;
        }
        Node current = head;
        while (current.next != null && current.next.employee.getId() != id) {
            current = current.next;
        }
        if (current.next != null) {
            current.next = current.next.next;
        }
    }


    // A function to check whether the list contain , returns a boolean , True or False
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

    // A function to print the list elements
    public void printList() {
        Node current = head;
        while (current != null) {
            System.out.println(current.employee);
            current = current.next;
        }
    }

    // node class
    private class Node {
        Employee employee;
        Node next;

        Node(Employee employee) {
            this.employee = employee;
        }
    }
}



