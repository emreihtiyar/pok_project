#if !define_SHELL_SORT_H_
#define _SHELL_SORT_H_ 

#define DEFINE_SHELL_SORT(SHEL_SORT, TYPE)/*n / 2, n / 4, n / 8, ... aralıklarda*/\
void SHEL_SORT(TYPE* dizi, int n){/* düzenleme yapılır*/\
  for (int ara = n / 2; ara > 0; ara /= 2) {/*diziyi geçici bir değişken'e ata.*/\
    for (int i = ara; i < n; i += 1) {\
      TYPE temp = dizi[i];\
      int j;\
      for (j = i; j >= ara && dizi[j - ara] > temp; j -= ara) {/* j aralıklarla*/\
        dizi[j] = dizi[j - ara];/* Sırala.*/\
      }\
    dizi[j] = temp;/*böylelikle dizi[j] sıralanmış bir dizyi oluşturmuştur.*/\
    }\
  }\
}\

DEFINE_SHELL_SORT(sort_char, char)
DEFINE_SHELL_SORT(sort_int, int)
DEFINE_SHELL_SORT(sort_float, float)
DEFINE_SHELL_SORT(sort_double, double)

#define SHELL_SORT(array, size) \
_Generic((array),       \
    int*: sort_int,       \
    float*: sort_float,   \
    double*: sort_double, \
    char*: sort_char      \
)(array, size)

#define DIZI_YAZDIR(arr,size,data_type) _Generic((data_type),int: int_yazdir,float: float_yazdir,double: double_yazdir,char: char_yazdir)(arr,size)


void int_yazdir(int arr[],int size);
void float_yazdir(float arr[],float size);
void double_yazdir(double arr[],double size);
void char_yazdir(char arr[],int size);
#endif // _SHELL_SORT_H_