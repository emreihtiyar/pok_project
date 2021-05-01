#define MAX_HEIGHT (32)

struct skiplist
{
    int key;
    int height;               /* katman sayisi */
    struct skiplist *next[1]; /* katmandaki isaretcileri tutan dizi */
};

typedef struct skiplist *Skiplist;

/* bos bir skip list olusturur*/
Skiplist skiplistCreate();

/* skip list'e ayrilmis hafizayi serbest birakir */
void skiplistDestroy(Skiplist s);

/* verilen skip list'te verilen degeri arar */
/* eger deger skip list icerisindeyse INT_MAX, degilse INT_MIN dondurur */
int skiplistSearch(Skiplist s, int key);

/* verilen skip list'e yeni bir dugum ekler */
void skiplistInsert(Skiplist s, int key);

/* verilen skip list'ten verilen degeri siler */
/* eger verilen deger skip list icerisinde bulunmuyorsa hicbir sey yapmaz */
void skiplistDelete(Skiplist s, int key);

/* verilen skip list'i ekrana yazdirir (en ust katmandan en alt katmana) */
void skiplistPrint(Skiplist s);
