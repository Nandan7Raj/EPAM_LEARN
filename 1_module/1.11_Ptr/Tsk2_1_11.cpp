//
// Created by NandanRaj on 25-01-2026.
//
#include<stdio.h>
#include<stdlib.h>
// Function to copy a string from source to a newly allocated destination
char* my_strcpy( const char* src)
{
    int len=0;
    // Calculate the length of the source string
    while(src[len]!='\0')
    {
        len++;
    }

    // Allocate memory for the destination string
    char* dest = (char*) malloc((len+1)*sizeof(char));
    // Check if memory allocation was successful
    if(dest == NULL)
    {
        return NULL; // Memory allocation failed
    }

    for(int i=0;i<len;i++)
    {
        dest[i]=src[i];// Copy each character from source to destination
    }
    dest[len] = '\0';// Null-terminate the destination string

    return dest;//  Return the pointer to the copied string
}

int main()
{
    // Test the my_strcpy function
    const char* original = "h";
    // call the function to copy the string
    char* copy = my_strcpy(original);
    if(copy != NULL)// Check if the copy was successful
    {
        printf("Original: %s\n", original);
        printf("Copy: %s\n", copy);
        free(copy); // Free the allocated memory
    }
    else
    {
        printf("Memory allocation failed\n");
    }

    return 0;
}