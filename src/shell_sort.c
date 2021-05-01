#include <stdio.h>
// !Printing int array
void int_yazdir(int arr[],int size){

    for (int i = 0; i < size; i++)
    {   
        printf("%d  ",arr[i]);
    }
    printf("\n");
    
}
// !Printing float array
void float_yazdir(float arr[],float size){

    for (int i = 0; i < size; i++)
    {   
        printf("%.2f  ",arr[i]);
    }
    printf("\n");    
}
// !Printing int array
void double_yazdir(double arr[],double size){

    for (int i = 0; i < size; i++)
    {   
        printf("%.4lf  ",arr[i]);
    }
    printf("\n");
    
}
// !Printing int array
void char_yazdir(char arr[],int size){

    for (int i = 0; i < size; i++)
    {   
        printf("%c  ",arr[i]);
    }
    printf("\n");
}