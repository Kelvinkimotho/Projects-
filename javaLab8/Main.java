package org.example;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class Main {
    public static void main(String[] args) {
        //creating objects for the classes
        SortedLinkedList sortedList = new SortedLinkedList();
        CircularLinkedList circularList = new CircularLinkedList();
        DoublyLinkedList doublyList = new DoublyLinkedList();
        // Reading  data from "emp.txt" file and populate the lists
        try (BufferedReader reader = new BufferedReader(new FileReader("emp.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(" ");
                int id = Integer.parseInt(parts[1]);
                String name = parts[0].trim();
                Employee employee = new Employee(id, name);

                sortedList.add(employee);
                circularList.insert(employee);
                doublyList.add(employee);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        // Part 1: Sorted LinkedList
        System.out.println("\n *** Sorted LinkedList ***\n");
        sortedList.printList();
        System.out.println("\nRemoving an element with ID 1905341731\n");
        sortedList.remove(1905341731);
        sortedList.printList();

        // Part 2: Circular LinkedList
        System.out.println("\n *** Circular LinkedList *********\n");
        circularList.display();
        System.out.println("\nDeleting an element with ID 484774148\n");
        circularList.delete(484774148);
        circularList.display();

        // Part 3: Doubly LinkedList
        System.out.println("\n**** Doubly LinkedList ***\n");
        doublyList.remove(1905341731);
        doublyList.add(new Employee(9, "John Doe"));
        System.out.println("Checking if ID 1905341731 exists " + doublyList.contains(1905341731));
        System.out.println("Checking if ID 9 exists " + doublyList.contains(9));
    }
}




