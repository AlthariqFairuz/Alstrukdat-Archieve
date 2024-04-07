#include "boolean.h"
#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik list1, list2, final;
    readList(&list1);
    readList(&list2);
    int nilai1 = 0, nilai2 = 0, mult;

    // Buat list 1
    for (int i = 0; i < listLength(list1); i++)
    {
        mult = 1;
        for (int j = 1; j < listLength(list1) - i; j++)
        {
            // Ambil angka dari depan dan kalikan dengan 10 sesuai posisi digitnya
            mult = mult * 10;
        }
        nilai1 = nilai1 + (ELMT(list1, i) * mult);
    }

    // Ulangi hal yanhg sama buat list 2
    for (int i = 0; i < listLength(list2); i++)
    {
        mult = 1;
        for (int j = 1; j < listLength(list2) - i; j++)
        {
            mult = mult * 10;
        }
        nilai2 = nilai2 + (ELMT(list2, i) * mult);
    }

    // Buat list terakhir yang menyimpan ahsil penjumlahan list sebelumnya
    int total = nilai1 + nilai2;
    CreateListStatik(&final);
    while (total > 0)
    {
        // Input nilai ke list dimulai dari yang paling belakang
        insertFirst(&final, total % 10);
        total = total / 10;
    }
    printList(final);
    printf("\n");
}
