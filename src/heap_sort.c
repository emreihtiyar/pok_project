#include <stdio.h>
// #include "heapsort.h"

// !Printing int array
void print_int(int arr[],int size){

    for (int i = 0; i < size; i++)
    {   
        printf("%d,",arr[i]);
    }
    printf("\n");
    
}
// !Printing float array
void print_float(float arr[],int size){

    for (int i = 0; i < size; i++)
    {   
        printf("%.2f,",arr[i]);
    }
    printf("\n");
    
}
// !Printing int array
void print_double(double arr[],int size){

    for (int i = 0; i < size; i++)
    {   
        printf("%.2lf,",arr[i]);
    }
    printf("\n");
    
}
// !Printing int array
void print_char(char arr[],int size){

    for (int i = 0; i < size; i++)
    {   
        printf("%c,",arr[i]);
    }
    printf("\n");
    
}