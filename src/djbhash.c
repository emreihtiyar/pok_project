#include "djbhash.h"

unsigned long djbhash(void *buff, int size)
{
    // bu algoritmanın sihirli sayısı
    unsigned long hash = 5381;
    int c;
    
    // gönderilen değişkenin byte sayısı kadar
    for (int i = 0; i < size; i++)
    {
        // algoritmayı çalıştır
        c = *(unsigned char *)buff++;
        hash = ((hash << 5) + hash) + c; // hash * 33 + hash
    }

    // sonucu döndür
    return hash;
}
