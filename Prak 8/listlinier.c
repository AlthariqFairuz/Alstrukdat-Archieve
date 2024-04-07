/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */
/* LIST = POINTER TO NODE, DEFINISI LIST SAMA DENGAN ADDRESS, YAITU SAMA SAMA POINTER TOP NODE */
#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* Definisi Node : */
typedef int ElType;
typedef struct node *Address; // Address = pointer to node (Alias pointer ke node, artinya jika kita declare tipe data Address, kita mendeclare pointer ke suatu Node)
typedef struct node
{
    ElType info;
    Address next;
} Node;

#define INFO(p) (p)->info // Buat amnbil elemen di node
#define NEXT(p) (p)->next // Buat ganti address ke next node

Address newNode(ElType val)
{
    // Fungsi buat transfer val/integer tertentu ke node baru
    Address new = (Address)malloc(sizeof(Node)); // new = pointer ke node (nama node itu sendiri tp tipenya pointer)

    INFO(new) = val;
    NEXT(new) = NULL;
    return new;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

typedef Address List; // List sebagai alias dari address, artinya list adalajh pointer ke node juga, yang mana merujuk ke elemen pertama dari linked list. Kita bisa bikin linked list kayak Address p atau List p

#define IDX_UNDEF (-1)
#define FIRST(l) (l) // Index pertama array = adress pertama

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
{
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
{
    /* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
{
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengembalikan nilai elemen l pada indeks idx */
    Address p = l;
    int i = 0;
    while (i < idx && p != NULL)
    {
        i++;
        p = NEXT(p);
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val)
{
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    Address p = *l;
    for (int i = 0; i < idx; i++)
    {
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val)
{
    /* I.S. l, val terdefinisi */
    /* F.S. Mencari apakah ada elemen list l yang bernilai val */
    /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
    /* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    Address p = l;
    int idx = 0;
    while (p != NULL)
    {
        if (INFO(p) == val)
        {
            return idx;
        }
        idx++;
        p = NEXT(p);
    }
    return IDX_UNDEF;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
{
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
    /* Jika alokasi gagal: I.S.= F.S. */
    Address new = newNode(val);
    if (new != NULL)
    {
        NEXT(new) = *l; // new->next = first
        *l = new;       // *l->first = new
    }
}

void insertLast(List *l, ElType val)
{
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    Address new = newNode(val);
    Address p = *l;
    if (isEmpty(*l))
    {
        insertFirst(l, val);
    }
    else
    {
        while (NEXT(p) != NULL)
        {
            p = NEXT(p);
        }
        NEXT(p) = new;
    }
}

void insertAt(List *l, ElType val, int idx)
{
    /* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
    /* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    Address new = newNode(val);
    Address p = *l;
    if (idx == 0)
    {
        insertFirst(l, val);
    }
    else
    {
        for (int i = 0; i < idx - 1; i++)
        {
            p = NEXT(p);
        }

        NEXT(new) = NEXT(p);
        NEXT(p) = new; // Tukar posisi next dari p ke new yang mana sebelumnya ke elemen setelah p
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
{
    /* I.S. List l tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen pertama di-dealokasi */
    Address p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}
void deleteLast(List *l, ElType *val)
{
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen terakhir di-dealokasi */
    Address p = FIRST(*l);
    Address q = NULL;
    while (NEXT(p) != NULL)
    {
        q = p;
        p = NEXT(p);
    }
    if (q == NULL)
    {
        *l = NULL;
    }
    else
    {
        NEXT(q) = NULL;
    }
    *val = INFO(p); // Simpan nilai node terakhir
    free(p);
}

void deleteAt(List *l, int idx, ElType *val)
{
    /* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. val diset dengan elemen l pada indeks ke-idx. */
    /*      Elemen l pada indeks ke-idx dihapus dari l */
    if (idx == 0)
    {
        deleteFirst(l, val);
    }
    else
    {
        int count = 0;
        Address p = *l;
        while (count < idx - 1)
        {
            count++;
            p = NEXT(p);
        }
        Address q = NEXT(p);
        *val = INFO(q);
        NEXT(p) = NEXT(q);
        free(q);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
{
    // void printInfo(List l);
    /* I.S. List mungkin kosong */
    /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    Address p = l;
    printf("[");
    while (p != NULL)
    {
        printf("%d", INFO(p));
        if (NEXT(p) != NULL)
        {
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]");
}

int length(List l)
{
    Address p = l;
    int cout = 1;
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        while (NEXT(p) != NULL)
        {
            cout++;
            p = NEXT(p);
        }
    }
    return cout;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
{
    /* I.S. l1 dan l2 sembarang */
    /* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
    /* Konkatenasi dua buah list : l1 dan l2    */
    /* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
    /* Tidak ada alokasi/dealokasi pada prosedur ini */
    List l3;
    CreateList(&l3);
    Address p = l1;
    while (p != NULL)
    {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p != NULL)
    {
        insertLast(&l3, INFO(p));
        Address q = NULL;
        p = NEXT(p);
    }
    return l3;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P)
{
    /* Mencari apakah ada elemen list yang beralamat P */
    /* Mengirimkan true jika ada, false jika tidak ada */
    Address p = L;
    while (p != NULL)
    {
        if (p == P)
        {
            return true;
        }
        p = NEXT(p);
    }
    return false;
}

Address searchPrec(List L, ElType X)
{
    /* Mengirimkan address elemen sebelum elemen yang nilainya=X */
    /* Mencari apakah ada elemen list dengan Info(P)=X */
    /* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
    /* Jika tidak ada, mengirimkan Nil */
    /* Jika P adalah elemen pertama, maka Prec=Nil */
    /* Search dengan spesifikasi seperti ini menghindari */
    /* traversal ulang jika setelah Search akan dilakukan operasi lain */
    Address p = L;
    // cek yang pertama
    if (INFO(p) == X)
    {
        return NULL;
    }
    // cek selain yang pertama
    while (NEXT(p) != NULL)
    {
        if (INFO(NEXT(p)) == X)
        {
            return p;
        }
        p = NEXT(p);
    }
    return NULL;
}

/*** Prekondisi untuk Max/Min/Rata-rata : List tidak kosong ***/
ElType maxValue(List l)
{
    /* Mengirimkan nilai info(P) yang maksimum */
    Address p = l;
    ElType max = INFO(p);
    while (p != NULL)
    {
        if (INFO(p) > max)
        {
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return max;
}

Address adrMax(List l)
{
    /* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    ElType maxVal = maxValue(l);
    Address p = l;
    while (INFO(p) != maxVal)
    {
        p = NEXT(p);
    } // INFO(p) == maxVal
    return p;
}

ElType minValue(List l)
{
    /* Mengirimkan nilai info(P) yang minimum */
    Address p = l;
    ElType min = INFO(p);
    while (p != NULL)
    {
        if (INFO(p) < min)
        {
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return min;
}

Address adrMin(List l)
{
    /* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    float average(List L);
    ElType minVal = minValue(l);
    Address p = l;
    while (INFO(p) != minVal)
    {
        p = NEXT(p);
    } // INFO(p) == minVal
    return p;
}

float average(List L)
{
    /* Mengirimkan nilai rata-rata info(P) */
    int count = 0, sum = 0;
    Address p = L;
    while (p != NULL)
    {
        sum += INFO(p);
        count++;
        p = NEXT(p);
    }
    return (float)sum / count;
}

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l)
{
    /* Delete semua elemen list dan alamat elemen di-dealokasi */
    ElType buang;
    while (length(*l) != 0)
    {
        deleteFirst(l, &buang);
    }
}

void copyList(List *l1, List *l2)
{
    /* I.S. L1 sembarang. F.S. L2=L1 */
    /* L1 dan L2 "menunjuk" kepada list yang sama.*/
    /* Tidak ada alokasi/dealokasi elemen */
    *l2 = *l1;
}

void inverseList(List *l)
{
    /* I.S. sembarang. */
    /* F.S. elemen list dibalik : */
    /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
    /* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

    int len = length(*l), i, idxInsert = 0;
    ElType val;
    for (i = 0; i < len; i++)
    {
        deleteLast(l, &val);
        insertAt(l, val, idxInsert);
        idxInsert++;
    }
}
#endif