#include <stdio.h>
#include "heap_sort.h"
int main(int argc, char const *argv[])
{
    //! Arrays
    int int_arr[] = {30, 10, 20, 0, 25, 5, 40, 35};
    float float_arr[] = {7.3, 20.1, 0.55, 1.2, 3.4, 5.6};
    double double_arr[] = {4.5, 9.4, 1.23, 4.5, 0.3};
    char char_arr[] = {'a', 'd', 'c', 'h', 'g', 'b', 'f','e'};
    
    // TODO Array sizes
    int int_size = sizeof(int_arr) / sizeof(int_arr[0]); 
    int float_size = sizeof(float_arr) / sizeof(float_arr[0]);
    int double_size = sizeof(double_arr) / sizeof(double_arr[0]);
    int char_size = sizeof(char_arr) / sizeof(char_arr[0]);

    // ** Array types
    int int_type;
    float float_type;
    double double_type;
    char char_type;

    //? Calling Funtions

//Todo: Calling heapsort and printing int array.
    printf("\n\t\t\tInteger Array\n");
    printf("Before sortiong: ");
    PRINT_ARR(int_arr, int_size, int_type);// Printing int array beforesortiong.
    HEAP_SORT(int_arr, int_size);// ! Heapsort calling for integer array.
    printf("After sortiong: ");
    PRINT_ARR(int_arr, int_size, int_type);// Printing int array after sortiong.


//Todo: Calling heapsort and printing float array.

    printf("\n\n\t\t\t Float Array\n"); 
    printf("Before sortiong: ");
    PRINT_ARR(float_arr, float_size, float_type);// Printing char array before sortiong.
    HEAP_SORT(float_arr, float_size);// ! Heapsort calling for float array.
    printf("After sortiong: ");
    PRINT_ARR(float_arr, float_size, float_type);// Printing float array after sortiong.

//Todo: Calling heapsort and printing double array.

    printf("\n\n\t\t\t Double Array\n");
    printf("Before sortiong: ");
    PRINT_ARR(double_arr, double_size, double_type);// Printing double array before sortiong.
    HEAP_SORT(double_arr, double_size); // ! Heapsort calling for double array.
    printf("After sortiong: ");
    PRINT_ARR(double_arr, double_size, double_type);// Printing double array after sortiong.


//Todo: Calling heapsort and printing char array.

    printf("\n\n\t\t\t Char Array\n"); 
    printf("Before sortiong: ");
    PRINT_ARR(char_arr, char_size, char_type);  // Printing char array before sortiong.
    HEAP_SORT(char_arr, char_size); // ! Heapsort calling for char array.
    printf("After sortiong: ");
    PRINT_ARR(char_arr, char_size, char_type); // Printing char array after sortiong.


    return 0;
}