#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>

#include "skiplist.h"

int main(int argc, char const *argv[])
{
    Skiplist s = skiplistCreate();

    for (int i = 0; i < 20; i++)
    {
        skiplistInsert(s, i);
    }

    printf("\nilk durum\n");
    skiplistPrint(s);
    skiplistDelete(s, 25);
    skiplistDelete(s, 26);
    skiplistDelete(s, 13);
    printf("\n25, 26 ve 13 silindi\n");
    skiplistPrint(s);

    printf("25'in arama sonucu: %d\n", skiplistSearch(s, 25));
    printf("10'un arama sonucu: %d\n", skiplistSearch(s, 10));

    skiplistDestroy(s);
    return 0;
}
