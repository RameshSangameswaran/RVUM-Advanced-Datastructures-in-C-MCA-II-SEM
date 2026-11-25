#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
// Stack Implementation
int stack[MAX];
int top = -1;
// Push Operation
void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}
// Pop Operation
int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
// ------------------------
// Postfix Expression Evaluation
// ------------------------
int evaluatePostfix(char exp[])
{
    int i, op1, op2, result;
    top = -1;
    for(i = 0; exp[i] != '\0'; i++)
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch(exp[i])
            {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
            }
        }
    }
    result = pop();
    return result;
}
// ------------------------
// Parenthesis Balancing
// ------------------------
int checkBalance(char expr[])
{
    int i;
    top = -1;
    for(i = 0; expr[i] != '\0'; i++)
    {
        if(expr[i] == '(')
        {
            push('(');
        }
        else if(expr[i] == ')')
        {
            if(top == -1)
                return 0;
            pop();
        }
    }
    return (top == -1);
}
// ------------------------
// Tower of Hanoi
// ------------------------
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n",
         source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n",
    n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}
// ------------------------
// Main Function
// ------------------------
int main()
{
    char postfix[MAX];
    char expression[MAX];
    int choice, result, n;
    do
    {
        printf("\n===== STACK APPLICATIONS =====\n");
        printf("1. Evaluate Postfix Expression\n");
        printf("2. Check Parenthesis Balance\n");
        printf("3. Tower of Hanoi\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Postfix Expression: ");
                scanf("%s", postfix);
                result = evaluatePostfix(postfix);
                printf("Result = %d\n", result);
                break;
            case 2:
                printf("Enter Expression: ");
                scanf("%s", expression);
                if(checkBalance(expression))
                    printf("Parentheses are Balanced\n");
                else
                    printf("Parentheses are Not Balanced\n");
                break;
            case 3:
                printf("Enter Number of Disks: ");
                scanf("%d", &n);
                printf("\nSteps:\n");
                towerOfHanoi(n, 'A', 'B', 'C');
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while(choice != 4);
    return 0;
}
//
// Created by rvu on 11/25/26.
//
