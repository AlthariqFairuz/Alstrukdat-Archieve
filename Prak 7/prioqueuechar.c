#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

boolean IsEmpty(PrioQueueChar Q)
{
    /* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull(PrioQueueChar Q)
{
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxEl */
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt(PrioQueueChar Q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmpty(Q))
    {
        return 0;
    }
    if (Head(Q) == Tail(Q))
    {
        return 1;
    }
    if (Head(Q) > Tail(Q))
    {
        return Tail(Q) - Head(Q) + MaxEl(Q) + 1;
    }
    return Tail(Q) - Head(Q) + 1;
}

void MakeEmpty(PrioQueueChar *Q, int Max)
{
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
    /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infotype *)malloc((Max + 1) * sizeof(infotype));
    if ((*Q).T != NULL)
    {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        MaxEl(*Q) = 0;
    }
}

void DeAlokasi(PrioQueueChar *Q)
{
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* Fungsi Tambahan */
int compare(const void *a, const void *b)
{
    infotype *x = (infotype *)a;
    infotype *y = (infotype *)b;
    return (x->prio > y->prio);
}

void addElement(PrioQueueChar *Q, infotype X)
{
    if (IsEmpty(*Q))
    {
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    else
    {
        if (Tail(*Q) == MaxEl(*Q) - 1)
        {
            Tail(*Q) = 0;
        }
        else
        {
            Tail(*Q)++;
        }
    }
    InfoTail(*Q) = X;
}

void Enqueue(PrioQueueChar *Q, infotype X)
{
    /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
            TAIL "maju" dengan mekanisme circular buffer; */
    int i, count;
    addElement(Q, X);
    count = NBElmt(*Q);
    infotype *temp = (infotype *)malloc(count * sizeof(infotype));
    for (i = 0; i < count; i++)
    {
        Dequeue(Q, &temp[i]);
    }
    qsort(temp, count, sizeof(infotype), compare);
    for (i = 0; i < count; i++)
    {
        addElement(Q, temp[i]);
    }
}

void Dequeue(PrioQueueChar *Q, infotype *X)
{
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */
    *X = Elmt(*Q, Head(*Q));
    if (NBElmt(*Q) == 1)
    {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        if (Head(*Q) == MaxEl(*Q) - 1)
        {
            Head(*Q) = 0;
        }
        else
        {
            Head(*Q)++;
        }
    }
}

void PrintPrioQueueChar(PrioQueueChar Q)
{
    /* Mencetak isi queue Q ke layar */
    /* I.S. Q terdefinisi, mungkin kosong */
    /* F.S. Q tercetak ke layar dengan format:
    <prio-1> <elemen-1>
    ...
    <prio-n> <elemen-n>
    #
    */
    int len = NBElmt(Q);
    for (int i = 0; i < len; i++)
    {
        printf("%d %c\n", Q.T[Head(Q)].prio, Q.T[Head(Q)].info);
        if (Head(Q) == MaxEl(Q))
        {
            Head(Q) = 1;
        }
        else
        {
            Head(Q)++;
        }
    }
    printf("#\n");
}
