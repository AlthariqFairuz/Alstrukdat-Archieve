/* File: queuelinked.h */

#ifndef QUEUELINKED_H
#define QUEUELINKED_H
#include "boolean.h"
#include <stdlib.h>

#define NIL NULL
/* Deklarasi infotype */
typedef int ElType;
/* Queue dengan representasi berkait dengan pointer */
typedef struct node *Address;
typedef struct node
{
    ElType info;
    Address next;
} Node;
/* Type queue dengan ciri HEAD dan TAIL: */
typedef struct
{
    Address addrHead; /* alamat penghapusan */
    Address addrTail; /* alamat penambahan */
} Queue;

/* Selektor */
#define NEXT(p) (p)->next
#define INFO(p) (p)->info

#define ADDR_HEAD(q) (q).addrHead
#define ADDR_TAIL(q) (q).addrTail
#define HEAD(q) (q).addrHead->info

/* Prototype manajemen memori */
Address newNode(ElType x)
{ /* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
    atau NIL jika alokasi gagal */
    Address p = (Address)malloc(sizeof(Node));
    if (p != NIL)
    {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

boolean isEmpty(Queue q)
{
    /* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
    return ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL;
}

int length(Queue q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        int count = 1;
        Address p = ADDR_HEAD(q);
        while (p != ADDR_TAIL(q))
        {
            count++;
            p = NEXT(p);
        }
        return count;
    }
}

/*** Kreator ***/
void CreateQueue(Queue *q)
{
    /* I.S. sembarang */
    /* F.S. Sebuah q kosong terbentuk */
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

void DisplayQueue(Queue q)
{
    /* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen
        dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah,
        atau di belakang, termasuk spasi dan enter */
    /* I.S. q boleh kosong */
    /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika Queue kosong : menulis [] */
    if (isEmpty(q))
    {
        printf("[]");
    }
    else
    {
        Address p = ADDR_HEAD(q);
        printf("[");
        while (NEXT(p) != NIL)
        {
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d]", INFO(p));
    }
}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x)
{
    /* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
               jika alokasi berhasil; jika alokasi gagal q tetap */
    /* Pada dasarnya adalah proses insertLast */
    /* I.S. q mungkin kosong */
    /* F.S. x menjadi Tail, Tail "maju" */
    Address p = newNode(x);
    if (p != NIL)
    {
        if (isEmpty(*q))
        {
            ADDR_HEAD(*q) = p;
            ADDR_TAIL(*q) = p;
        }
        else
        {
            NEXT(ADDR_TAIL(*q)) = p;
            ADDR_TAIL(*q) = p;
        }
    }
}

void dequeue(Queue *q, ElType *x)
{
    /* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
    /* Pada dasarnya operasi deleteFirst */
    /* I.S. q tidak mungkin kosong */
    /* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
    Address p = ADDR_HEAD(*q);
    *x = INFO(p);
    if (ADDR_HEAD(*q) == ADDR_TAIL(*q))
    {
        ADDR_HEAD(*q) = NIL;
        ADDR_TAIL(*q) = NIL;
    }
    else
    {
        ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    }
    free(p);
}

#endif