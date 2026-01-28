#include <stdio.h>

// Simple binary operations returning int results
int add(int a, int b) {
    return a + b; // sum
}

int sub(int a, int b) {
    return a - b; // difference
}

int mul(int a, int b) {
    return a * b; // product of a and b
}

// Division with a basic check for division by zero.
// If b == 0 the function returns a+1 as an error sentinel (handled by caller).
int divide(int a, int b) {
    if (b == 0)
        return a + 1;
    return a / b;
}

// calculate executes the operation function pointer on a and b.
// operation is a pointer to a function taking two ints and returning an int.
int calculate(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}


int main() {
    int a, b;
    char op;

    // Prompt for two integers
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    // Read an operation character.
    // Leading space in the format string skips any leftover whitespace/newline.
    printf("Enter operation: ");
    scanf(" %c", &op);

    // Demonstrate using calculate with different operation function pointers
    switch (op) {

        case '+': {
            const int sum = calculate(a, b, add);
            printf("Sum of %d and %d is: %d\n", a, b, sum);
            break;
        }

        case '-': {
            const int diff = calculate(a, b, sub);
            printf("Difference of %d and %d is: %d\n", a, b, diff);
            break;
        }
        case '*': {
            const int prod = calculate(a, b, mul);
            printf("Multiplication of %d and %d is: %d\n", a, b, prod);
            break;
        }
        case '/': {
            // Division result uses the special sentinel to indicate division by zero
            const int quot = calculate(a, b, divide);
            if (b == 0) {
                printf("Cannot divide by zero\n");
            } else {
                printf("Division: %d\n", quot);
            }
        }


        default:
            printf("invalid operand\n");
    }

    return 0;
}