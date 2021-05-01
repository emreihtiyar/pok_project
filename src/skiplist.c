#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#include "skiplist.h"

/* yeni olusturulacak dugum icin rasgele bir yukseklik secer (yazi-tura mantigi ile) */
static int chooseHeight()
{
    // dugumun yuksekligi olacak degisken
    int i;

    // yukseklik maksimum yukseklikten kucuk oldugu ve yazi geldigi surece i'nin degerini
    // arttirmaya devam ediyoruz
    for (i = 1; i < MAX_HEIGHT && rand() % 2 == 0; i++)
        ;

    // yuksekligi donduruyoruz
    return i;
}

/* verilen deger ve yukseklik ile yeni bir dugum olusturur */
static Skiplist skiplistCreateNode(int key, int height)
{
    // yeni dugum degiskenini olusturuyoruz
    Skiplist s;

    // dugum icin verilen yuksekligin (0 < yukseklik <= maksimum yukseklik) formulune
    // uydugunu garanti altina aliyoruz
    assert(height > 0);
    assert(height <= MAX_HEIGHT);

    // dugum icin hafiza ayirarak dugumu olusturuyoruz
    s = malloc(sizeof(struct skiplist) + sizeof(struct skiplist *) * (height - 1));

    // yeni dugumun basarili bir sekilde olustugundan emin oluyoruz
    assert(s);

    // olusturulan dugumun verisini ve yuksekligini atiyoruz
    s->key = key;
    s->height = height;

    // olusturdugumuz dugumu donduruyoruz
    return s;
}

Skiplist skiplistCreate()
{
    // skip list'in sentinel denilen kismini olusturuyoruz. bu kisim, tum katmanlara
    // giden isaretcilerin basladigi kisim. ornek:
    /*
        . -> 10
        . -> 2 -> 10 -> 14 -> 16
        . -> 0 -> 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> 14 -> 16 -> 18
    */
    // bu noktalar ile belirtilen kismi olusturuyoruz yani.
    Skiplist s = skiplistCreateNode(INT_MIN, MAX_HEIGHT);

    // sentinelin yuksekligini 1 yapiyoruz (simdilik tek katmanimiz var)
    s->height = 1;

    // tum dugumleri NULL yapiyoruz
    for (int i = 0; i < MAX_HEIGHT; i++)
    {
        s->next[i] = NULL;
    }

    return s;
}

void skiplistDestroy(Skiplist s)
{
    Skiplist next;

    // skip list'te bulunan tum dugumler icin ayrilan hafizayi serbest birakiyoruz
    while (s)
    {
        next = s->next[0];
        free(s);
        s = next;
    }
}

int skiplistSearch(Skiplist s, int key)
{
    // en yuksek katmandan en alt katmana dogru ariyoruz
    for (int level = s->height - 1; level >= 0; level--)
    {
        // katmandaki tum dugumleri donecek iterator pointeri olusturuyoruz
        Skiplist iter = s->next[level];
        // dugum null olmadigi surece
        while (iter)
        {
            // eger bulduysak, INT_MAX donduruyoruz
            if (iter->key == key)
                return INT_MAX;
            // dugumdeki deger aradigimiz sayidan buyukse while dongusunden cikiyoruz
            // ki alttaki katmana inelim
            else if (iter->key > key)
                break;
            // dugumdeki deger aradigimiz sayidan kucukse o katmanda bulunan siradaki
            // dugume gidiyoruz
            else if (iter->key < key)
                iter = iter->next[level];
        }
    }

    // aradigimiz deger bulunamadigindan INT_MIN degerini donduruyoruz
    return INT_MIN;
}

void skiplistInsert(Skiplist s, int key)
{
    // ekleme yapacagimiz katmani tutacak degiskeni tanimliyoruz
    int level;

    // rasgele yukseklikte bir dugum olusturuyoruz
    Skiplist elt = skiplistCreateNode(key, chooseHeight());

    // dugumumuzun olustugundan emin oluyoruz
    assert(elt);

    // eger olusturdugumuz dugumun yuksekligi sentinelimizinkinden fazlaysa
    // sentinelimizin yuksekligini yeni olusturdugumuz dugumun yuksekligine esitliyoruz
    if (elt->height > s->height)
    {
        s->height = elt->height;
    }

    // en yuksek dugumden olusturdugumuz dugumun yuksekligine kadarki tum katmanlari
    // yuksekten alcaga olacak sekilde geziyoruz
    for (level = s->height - 1; level >= elt->height; level--)
    {
        while (s->next[level] && s->next[level]->key < key)
        {
            s = s->next[level];
        }
    }

    // ekleme yapacagimiz seviyeye geldik, bu seviyeden itibaren dugumleri
    // arayarak s dugumunu bulundugumuz katmanda verilen degerden kucuk
    // en buyuk degeri tutan dugum olarak guncelliyoruz
    for (; level >= 0; level--)
    {
        while (s->next[level] && s->next[level]->key < key)
        {
            s = s->next[level];
        }

        // s, bu katmanda verilen degerden kucuk en buyuk deger oldu
        // s'in sagina verilen degerle olusturdugumuz dugumu bagliyoruz
        elt->next[level] = s->next[level];
        s->next[level] = elt;
    }
}

void skiplistDelete(Skiplist s, int key)
{
    int level;
    Skiplist target;

    // en ust katmandan baslayarak verilen degeri bulunduran dugumu ariyoruz
    target = s;
    for (level = s->height - 1; level >= 0; level--)
    {
        while (target->next[level] && target->next[level]->key < key)
        {
            target = target->next[level];
        }
    }

    // target degiskeni, aradigimiz dugumden bir onceki dugum
    // bundan dolayi bir sonraki dugume geciyoruz
    target = target->next[0];

    // eger NULL degere geldiysek ya da buldugumuz dugum aradigimiz degeri barindirmiyorsa
    // aradigimiz dugumu bulamadik demektir, hicbir sey yapmadan donuyoruz
    if (target == NULL || target->key != key)
    {
        return;
    }

    // hala donmediysek dugum skip list'imizde var demektir, en yuksek katmandan baslayarak
    // (en solda bulunacagi yerlerden) dugumu listeden kopariyoruz
    for (level = s->height - 1; level >= 0; level--)
    {
        while (s->next[level] && s->next[level]->key < key)
        {
            s = s->next[level];
        }

        if (s->next[level] == target)
        {
            s->next[level] = target->next[level];
        }
    }

    // dugum tarafindan tutulan hafizayi serbest birakiyoruz
    free(target);
}

void skiplistPrint(Skiplist s)
{
    // en ust katmandan en alt katmana dogru iniyoruz
    for (int level = s->height - 1; level >= 0; level--)
    {
        // her katman icerisinde dolasacak pointeri tanimliyoruz
        Skiplist iter = s->next[level];
        // hangi katmanda oldugumuzu yazdiriyoruz
        printf("%d. level: ", level);
        // bu katmanda bulunan dugum NULL olmadikca
        while (iter)
        {
            // dugumun degerini ekrana yazdiriyoruz
            printf("%d ", iter->key);
            // siradaki dugume geciyoruz
            iter = iter->next[level];
        }
        // yeni satir yazdiriyoruz
        printf("\n");
    }
}
