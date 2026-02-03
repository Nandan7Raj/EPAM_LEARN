//
// Created by NandanRaj on 25-01-2026.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *colour_code= (int*)malloc(sizeof(int));
    if (colour_code == NULL) {
        printf("Dynamic memory allocation Unsuccessful\n");
        return 1;
    }
    *colour_code= 0;//default value
    // we can also use calloc
    // int *colour_code = calloc(1,sizeof(int));
    do {
        printf("Enter your preferred colour code(0-7) : ");
       if (scanf("%d",colour_code)!=1) {// to handel invalid input like float, char
           printf("Invalid input\n");
           while (getchar()!='\n');
       }

    }while (*colour_code < 0 || *colour_code > 7);
    printf("Your colour code is: %d\n",*colour_code);
    free(colour_code);
    colour_code= NULL;
    return 0;
}
