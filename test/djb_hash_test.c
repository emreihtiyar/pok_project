#include <stdio.h>
#include <string.h>

#include "djbhash.h"

// farklı tipte değişkenler kullanılarak hash fonksiyonunun 
// generic çalışması kontrol ediliyor
void do_tests()
{
    short short_data = 123;
    int int_data = 713;
    float float_data = 122.41;
    double double_data = 512.7613;
    long long_data = 27636233;
    char char_data = 'c';
    char *str_data = "hello world!";

    printf("\n*****START OF THE TESTS*****\n\n");
    printf("short variable 123 hash -> %lu\n", djbhash(&short_data, sizeof(short)));
    printf("int variable 713 hash -> %lu\n", djbhash(&int_data, sizeof(int)));
    printf("float variable 122.41 hash -> %lu\n", djbhash(&float_data, sizeof(float)));
    printf("double variable 512.7613 hash -> %lu\n", djbhash(&double_data, sizeof(double)));
    printf("long variable 27636233 hash -> %lu\n", djbhash(&long_data, sizeof(long)));
    printf("char variable 'c' hash -> %lu\n", djbhash(&char_data, sizeof(char)));
    printf("char* (string) variable \"hello world!\" hash -> %lu\n", djbhash(str_data, strlen(str_data)));
    printf("\n*****END OF THE TESTS*****\n\n");
}

void do_tests();

int main()
{
    do_tests();
    return 0;
}