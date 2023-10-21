package org.example;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("emp.txt"));
            String line;
            int numOfEmployees = 0;
            while ((line = reader.readLine()) != null) {
                numOfEmployees++;
            }
            reader.close();

            employee[] employees = new employee[numOfEmployees];
            reader = new BufferedReader(new FileReader("emp.txt"));
            int i = 0;

            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(" ");
                int id = Integer.parseInt(parts[1]);
                String name = parts[0];
                employees[i] = new employee(id, name);
                i++;
            }

            employee.selectionSort(employees, 0, numOfEmployees - 1);
            System.out.println("\n***********PART1 RESULTS*************8\n");
            // Printing  the sorted array of employees
            System.out.println("\nBellow is a sorted list of employees details \n");
            for (employee employee : employees) {
                System.out.println(employee.name + " " + employee.id);
            }

            // Testing  binary search function
            int targetID = 1905341731; // testing the function with the following details "Royce 1905341731"
            int result = employee.binarySearch(employees, 0, numOfEmployees - 1, targetID);

            if (result != -1) {
                System.out.println("Employee found at index:  " + result);
            } else {
                System.out.println("Employee not found");
            }

        } catch (IOException e) {
            e.printStackTrace();
        }


        ///PROBLEM 2


        InfixToPostfix infixEvaluator = new InfixToPostfix();

        String[] infixExpressions = {"1+3*8", "8-3-4*6+3", "8-2+8/4+6-1-6/2"};
        System.out.println("\n*****************PART 2 RESULTS***********\n");
        for (String infixExpression : infixExpressions) {
            String postfix = infixEvaluator.infixToPostfix(infixExpression);
            System.out.println("Infix Expression is " + infixExpression);
            System.out.println("Postfix Expression is " + postfix);
            int result = infixEvaluator.evaluatePostfix(postfix);
            System.out.println("Evaluation is  " + result);
            System.out.println();
        }




        ///PROBLEM 3
        PalindromeChecker palindrom1=new PalindromeChecker();
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n ************PART3 RESULTS ***********\n");
        System.out.println("\nEnter a string to check if it's a palindrome ");
        String input = scanner.nextLine();

        if (palindrom1.isPalindrome(input)) {
            System.out.println("The input "+input +" is a palindrome.");
        } else {
            System.out.println("The input"+ input +" is not a palindrome.");
        }

    }
}










