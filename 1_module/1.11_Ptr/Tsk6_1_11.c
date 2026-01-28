//
// Created by NandanRaj on 25-01-2026.
//

#include<stdio.h>
// func for addition
int add(int a,int b) {
    printf("Addition Result: ");
    return a+b;
}
// func for subtraction
int sub(int a,int b) {
    printf("Subtraction Result: ");
    return a-b;
}
// func for multiplication
int mul(int a,int b) {
    printf("Multiplication Result: ");
    return a*b;
}
int main() {
    int (*funcPtr)(int,int)=NULL; // function pointer array
    int a,b;
    char opr;
    // user input
    printf("Enter two Integer :");
     scanf("%d %d",&a,&b);
    printf("Enter operator: ");
     scanf(" %c",&opr);
    switch (opr) {
        case '+': // if user choose '+' then funcPtr will point to add
            funcPtr=add;
            break;
        case '-': // if user choose '-' then funcPtr will point to sub
            funcPtr=sub;
            break;
        case '*': // if user choose '*' then funcPtr will point to mul
            funcPtr=mul;
            break;
        default:
            printf("Invalid Operator\n");
    }
    if (funcPtr!=NULL) {
        int res=funcPtr(a,b); // funcPtr will be pointing to a specific func according to user choice
        printf("%d\n",res);// printing of res
    }
    printf("Thank You");
    return 0;

}
