package org.example;
import java.util.Stack;
public class InfixToPostfix {
    public static String infixToPostfix(String expression) {
        StringBuilder postfix = new StringBuilder();
        Stack<Character> operatorStack = new Stack<>();

        for (char token : expression.toCharArray()) {
            if (Character.isDigit(token)) {
                postfix.append(token);
            } else if (token == '+' || token == '-' || token == '*' || token == '/') {
                while (!operatorStack.isEmpty() && getPrecedence(operatorStack.peek()) >= getPrecedence(token)) {
                    postfix.append(operatorStack.pop());
                }
                operatorStack.push(token);
            }
        }

        while (!operatorStack.isEmpty()) {
            postfix.append(operatorStack.pop());
        }

        return postfix.toString();
    }

    public static int evaluatePostfix(String postfixExpression) {
        Stack<Integer> operandStack = new Stack<>();

        for (char token : postfixExpression.toCharArray()) {
            if (Character.isDigit(token)) {
                operandStack.push(Character.getNumericValue(token));
            } else {
                int operand2 = operandStack.pop();
                int operand1 = operandStack.pop();
                int result = performOperation(operand1, operand2, token);
                operandStack.push(result);
            }
        }

        return operandStack.pop();
    }

    private static int getPrecedence(char operator) {
        if (operator == '+' || operator == '-') {
            return 1;
        } else if (operator == '*' || operator == '/') {
            return 2;
        }
        return 0;
    }

    private static int performOperation(int operand1, int operand2, char operator) {
        switch (operator) {
            case '+':
                return operand1 + operand2;
            case '-':
                return operand1 - operand2;
            case '*':
                return operand1 * operand2;
            case '/':
                if (operand2 == 0) {
                    throw new ArithmeticException("Division by zero");
                }
                return operand1 / operand2;
            default:
                throw new IllegalArgumentException("Invalid operator: " + operator);
        }
    }
}
