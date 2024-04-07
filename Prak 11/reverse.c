#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

int main()
{
    List l, l2, l3, l4;
    l = NULL;
    l2 = NULL;
    l3 = NULL;
    l4 = NULL;
    int size, n;
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &n);
        l = konsb(l, n);
    }
    int ulang;
    scanf("%d", &ulang);
    for (int i = 0; i < ulang; i++)
    {
        int idx;
        scanf("%d", &idx);
        while (idx > 0)
        {
            l2 = konsb(l2, head(l));
            l = tail(l);
            idx -= 1;
        }
        int panjang1 = length(l);
        int panjang2 = length(l2);
        for (int i = 0; i < panjang2; i++)
        {
            l4 = konso(l4, head(l2));
            l2 = tail(l2);
        }
        for (int i = 0; i < panjang1; i++)
        {
            l3 = konso(l3, head(l));
            l = tail(l);
        }
        l = concat(l4, l3);
        l2 = NULL;
        l3 = NULL;
        l4 = NULL;
    }
    displayList(l);
}
