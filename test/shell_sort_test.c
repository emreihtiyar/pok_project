#include <stdio.h>
#include <unistd.h>
#include "shell_sort.h"
//enum dtipi {int_tipi,double_tipi,char_tipi};
int main(void){

    int int_dizi[] = {7, 1, 24, 3, 25, 15, 46, 4};
    float float_dizi[] = {7.32, 26.11, 20.55, 11.23, 36.47, 35.76};
    double double_dizi[] = {43.5131, 9.4312, 1.2334, 42.5421, 0.3341};
    char char_dizi[] = {'a', 'd', 'c', 'h', 'g', 'b', 'e', 'f'};

    int int_size = sizeof(int_dizi) / sizeof(int_dizi[0]); 
    float float_size = sizeof(float_dizi) / sizeof(float_dizi[0]);
    double double_size = sizeof(double_dizi) / sizeof(double_dizi[0]);
    int char_size = sizeof(char_dizi) / sizeof(char_dizi[0]);

    int int_tipi;
    float float_tipi;
    double double_tipi;
    char char_tipi;


    printf("Int tipinde olan Dizi\n");
    printf("Sıralanmadan önce : ");
    DIZI_YAZDIR(int_dizi, int_size, int_tipi);
    SHELL_SORT(int_dizi, int_size);
    printf("Sıralandıktan Sonra: ");

    DIZI_YAZDIR(int_dizi, int_size, int_tipi);

    printf("Float tipinde olan Dizi\n");
    printf("Sıralanmadan önce : ");
    DIZI_YAZDIR(float_dizi, float_size, float_tipi);
    SHELL_SORT(float_dizi, float_size);
    printf("Sıralandıktan sonra : ");
    DIZI_YAZDIR(float_dizi, float_size, float_tipi);

    printf("Double tipinde olan Dizi\n");
    printf("Sıralanmadan önce : ");
    DIZI_YAZDIR(double_dizi, double_size, double_tipi);
    SHELL_SORT(double_dizi, double_size);
    printf("Sıralandıktan sonra : ");
    DIZI_YAZDIR(double_dizi, double_size, double_tipi);

    printf("Char  tipinde olan Dizi\n");
    printf("Sıralanmadan önce : ");
    DIZI_YAZDIR(char_dizi, char_size, char_tipi);
    SHELL_SORT(char_dizi, char_size);
    printf("Sıralandıktan sonra : ");
    DIZI_YAZDIR(char_dizi, char_size, char_tipi);
    return 0;
}