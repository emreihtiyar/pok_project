#if !defined(__HEAPS__)
#define __HEAPS__
#include<stdio.h>

//! Complete heap_sort algorithm.
#define DEFINE_HEAP_SORT(FNAME, TYPE) \
void FNAME(TYPE* arr, int size) { \
    int  i, j, c, root;\
    TYPE temp;\
    for (i = 1; i < size; i++)\
    {\
        c = i;\
        do\
        {\
            root = (c - 1) / 2;             \
            if (arr[root] < arr[c])   /* to make max_heap array */\
            {\
                temp = arr[root]; \
                arr[root] = arr[c];\
                arr[c] = temp;\
            }\
            c = root;\
        } while (c != 0);\
    }\
    for (j = size - 1; j >= 0; j--)\
    {\
        temp = arr[0];\
        arr[0] = arr[j];   /* swap max element with rightmost leaf element */\
        arr[j] = temp;\
        root = 0;\
        do \
        {\
            c = 2 * root + 1;    /* left node of root element */\
            if ((arr[c] < arr[c + 1]) && c < j-1)\
                c++;\
            if (arr[root]<arr[c] && c<j)    /* again rearrange to max_heap array */\
            {\
                temp = arr[root];\
                arr[root] = arr[c];\
                arr[c] = temp;\
            }\
            root = c;\
        } while (c < j);\
    }\
}
DEFINE_HEAP_SORT(sort_char, char) //* Defining heapsort for char types
DEFINE_HEAP_SORT(sort_int, int)   //* Defining heapsort for int types
DEFINE_HEAP_SORT(sort_float, float)//* Defining heapsort for float types
DEFINE_HEAP_SORT(sort_double, double)//* Defining heapsort for double types


//todo: Macro which calls heap_sort Funtion according to the data types.
#define HEAP_SORT(array, size)\
_Generic((array),       \
    int*: sort_int,       \
    float*: sort_float,   \
    double*: sort_double, \
    char*: sort_char      \
)(array, size)

//todo: Macro which calls different printing funtions.(int,double,float,char)
#define PRINT_ARR(arr,size,data_type) _Generic((data_type),int: print_int,float: print_float,double: print_double,char: print_char)(arr,size)

//! Protoypes for printing elements of arrays of different types.
void print_int(int arr[],int size);
void print_float(float arr[],int size);
void print_double(double arr[],int size);
void print_char(char arr[],int size);
#endif
