#include "boolean.h"
#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik rumah, jalan;
    int truk1 = 0, truk2 = 0, truk3 = 0, menitjalan = 0, menit = 0;

    readList(&rumah);
    readList(&jalan);
    insertFirst(&jalan, 0);
    for (int i = 0; i < listLength(rumah); i++)
    {
        menitjalan += ELMT(jalan, i);
        if (ELMT(rumah, i) == 1)
        {
            truk1 = menitjalan;
            menit = menit + 1;
        }
        if (ELMT(rumah, i) == 2)
        {
            truk2 = menitjalan;
            menit = menit + 1;
        }
        if (ELMT(rumah, i) == 3)
        {
            truk3 = menitjalan;
            menit = menit + 1;
        }
    }
    int total = menit + truk1 * 2 + truk2 * 2 + truk3 * 2;
    printf("%d\n", total);
}
