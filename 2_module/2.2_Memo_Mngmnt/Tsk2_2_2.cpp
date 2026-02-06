//
// Created by NandanRaj on 04-02-2026.
//
#include <iostream>

int main(int argc, char *argv[]) {
    //Dynamic memory allocation using "new"
    int* arr1=new int[5];
    // here we do not need to type cast from void* to int* as int*  ptr only
    // first it create memory of particular size (here 4byts(int)) using operator new and address of that memory is stored in a void* pointer
    // then pointer of int* pointing to the address is created using new placement (constructor called)
    //Dynamic memory allocation using "malloc"
    int* arr2= (int*)malloc(5*sizeof(int));
    // here it return void ptr pointing to add reserved for memory
    // here no automatic constructor called
    for (int i=0;i<5;i++) {
        arr1[i]=i;
        arr2[i]=i;
    }
    std::cout<<"Array1(created using new keyword):";
    for (int i=0;i<5;i++) {
        std::cout<<arr1[i]<<" ";
    }
    std::cout<<"\nArray1(created using malloc keyword):";
    for (int i=0;i<5;i++) {
        std::cout<<arr2[i]<<" ";
    }
    delete[] arr1;
    std::cout<<"arr1 memory freed"<<std::endl;
    free(arr2);
    std::cout<<"arr2 memory freed"<<std::endl;
}
