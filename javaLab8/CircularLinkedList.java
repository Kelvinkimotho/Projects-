package org.example;

public class CircularLinkedList {
    private Node head;

    //a function to an employee node to the list
    public void insert(Employee employee) {
        Node newNode = new Node(employee);
        if (head == null) {
            head = newNode;
            head.next = head;
        } else {
            newNode.next = head.next;
            head.next = newNode;
        }
    }


    //A function to delete A node from the list
    public void delete(int id) {
        if (head == null) {
            return;
        }
        if (head.employee.getId() == id) {
            if (head.next == head) {
                head = null;
            } else {
                head.next = head.next.next;
            }
            return;
        }
        Node current = head;
        while (current.next != head && current.next.employee.getId() != id) {
            current = current.next;
        }
        if (current.next != head) {
            current.next = current.next.next;
        }
    }

    // A function to display LIst elements
    public void display() {
        if (head == null) {
            System.out.println("Circular Linked List is empty.");
            return;
        }
        Node current = head;
        do {
            System.out.println(current.employee);
            current = current.next;
        } while (current != head);
    }

    // A node class
    private class Node {
        Employee employee;
        Node next;

        Node(Employee employee) {
            this.employee = employee;
        }
    }
}




