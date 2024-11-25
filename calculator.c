#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double performOperation(double num1, double num2, char operator);
bool isValidOperator(char operator);

int main() {
    double result = 0.0;
    double num1, num2;
    char operator;
    bool firstCalculation = true;
    char continueCalc;

    printf("Simple Calculator\n");
    printf("----------------\n");

    do {
        if (firstCalculation) {
            printf("Enter first number: ");
            if (scanf("%lf", &num1) != 1) {
                printf("Invalid input. Please enter a number.\n");
                return 1;
            }
            firstCalculation = false;
        } else {
            num1 = result;
            printf("Current result: %.2f\n", result);
        }

        printf("Enter operator (+, -, *, /): ");
        scanf(" %c", &operator);

        if (!isValidOperator(operator)) {
            printf("Invalid operator. Please use +, -, *, or /.\n");
            continue;
        }

        printf("Enter next number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }

        if (operator == '/' && num2 == 0) {
            printf("Error: Division by zero is not allowed.\n");
            continue;
        }

        result = performOperation(num1, num2, operator);
        printf("Result: %.2f\n", result);

        printf("Do you want to continue calculating? (y/n): ");
        scanf(" %c", &continueCalc);

    } while (continueCalc == 'y' || continueCalc == 'Y');

    printf("Final result: %.2f\n", result);
    printf("Thank you for using my Simple Calculator!\n");

    return 0;
}

double performOperation(double num1, double num2, char operator) {
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0.0; 
    }
}

bool isValidOperator(char operator) {
    return (operator == '+' || operator == '-' || operator == '*' || operator == '/');
}