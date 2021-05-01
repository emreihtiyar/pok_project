#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbt.h"

int main(int argc, char const *argv[])
{
//!------------------------------------------------------ İNT ----------------------------------------------------
    printf("\n----INT----\n");
    node* root = init(15); 
    insert(root, 20);
    insert(root, 9);
    insert(root, 12);
    insert(root, 11);
    insert(root, 21);
    insert(root, 17);
    insert(root, 18);
    insert(root, 0);

    printf("Sol->Kök->Sağ şeklinde dolaşım: ");
    in_order_travelsal(root);// Sol Root Sağ
    printf("\n");
    printf("Kök->Sağ->Sol şeklinde dolaşım: ");
    pre_order_travelsal_int(root);// Root Sağ Sol
    printf("\n");
    printf("Sol->Sağ->Kök şeklinde dolaşım: ");
    post_order_travelsal_int(root);// Sol Sqğ Root
    printf("\n");

    printf("%d Agacta var mi?: -%s\n",0, find(root, 0) ? "Var":"Yok");
    printf("%d Agacta var mi?: -%s\n",142, find(root, 142) ? "Var":"Yok");

    printf("minimum: %d\n", min(root));
    printf("maximum: %d\n", max(root));

//!------------------------------------------------------ FLOAT ----------------------------------------------------
    printf("\n----FLOAT----\n");
    node_f* root_f = init(3.56f);
    insert(root_f, 1.46f);
    insert(root_f, 7.14f);
    insert(root_f, 19.75f);
    insert(root_f, 2.35f);
    insert(root_f, 2.737f);
    insert(root_f, 91.63f);
    printf("Sol->Kök->Sağ şeklinde dolaşım: ");
    in_order_travelsal(root_f);
    printf("\n");

    printf("%.2f Agacta var mi?: -%s\n",3.21f, find(root_f, 3.21f) ? "Var":"Yok");
    printf("%.2f Agacta var mi?: -%s\n",3.32f, find(root_f, 3.32f) ? "Var":"Yok");
    printf("minimum: %f\n", min(root_f));
    printf("maximum: %f\n", max(root_f));

//!------------------------------------------------------ DOUBLE ----------------------------------------------------
    printf("\n----DOUBLE----\n");
    node_d* root_d = init(3.32);
    insert(root_d, 2.34);
    insert(root_d, 8.14);
    insert(root_d, 4.75);
    insert(root_d, 2.25);
    insert(root_d, 14.87);
    insert(root_d, 4.55);

    printf("Sol->Kök->Sağ şeklinde dolaşım: ");
    in_order_travelsal(root_d);
    printf("\n");

    printf("%.2F Agacta var mi?: -%s\n",3.21, find(root_d, 3.21) ? "Var":"Yok");
    printf("%.2F Agacta var mi?: -%s\n",3.32, find(root_d, 3.32) ? "Var":"Yok");
    printf("minimum: %F\n", min(root_d));
    printf("maximum: %F\n", max(root_d));

//!------------------------------------------------------ STRING ----------------------------------------------------
    printf("\n----STRING----\n");
    node_s* root_s = init("h");
    insert(root_s, "d");
    insert(root_s, "i");
    insert(root_s, "e");
    insert(root_s, "k");
    insert(root_s, "n");
    insert(root_s, "z");

    printf("Sol->Kök->Sağ şeklinde dolaşım: ");
    in_order_travelsal(root_s);
    printf("\n");
    printf("%s Agacta var mi?: -%s\n", "m", find(root_s, "m") ? "Var":"Yok");
    printf("%s Agacta var mi?: -%s\n", "z", find(root_s, "z") ? "Var":"Yok");
    printf("minimum: %s\n", min(root_s));
    printf("maximum: %s\n", max(root_s));
    return 0;
}