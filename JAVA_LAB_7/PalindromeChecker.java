package org.example;

public class PalindromeChecker {
    // A Function to check if a string is a palindrome
    public static boolean isPalindrome(String input) {
        // Removing  spaces and converting the string  to lowercase for case-insensitive comparison
        String cleanInput = input.replaceAll("\\s", "").toLowerCase();
        int length = cleanInput.length(); //number of characters in the input string

        for (int i = 0; i < length / 2; i++) {
            if (cleanInput.charAt(i) != cleanInput.charAt(length - i - 1)) {
                return false; // Characters do not match, thus  not a palindrome
            }
        }

        return true; // All characters match, it's a palindrome
    }

}





