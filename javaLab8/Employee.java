package org.example;

public class Employee {
    private int id; // employee id variable
    private String name; //employee name

    // A employee constructor
    public Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }
    // A function to get employees id , returns an integer

    public int getId() {
        return id;
    }
    // A function to get employees name , returns an string
    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }



}





