/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan Address adalah pointer */
/* ElType adalah integer */

#ifndef LISTCIRCULAR_H
#define LISTCIRCULAR_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

typedef int ElType;
typedef struct node *Address;
typedef struct node
{
	ElType info;
	Address next;
} ElmtList;
typedef struct
{
	Address first;
} List;

/* Definisi list : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), NEXT(P) */
/* Elemen terakhir list: jika Addressnya Last, maka NEXT(Last)=FIRST(l) */

/* Selektor */
#define INFO(P) (P)->info
#define NEXT(P) (P)->next
#define FIRST(l) ((l).first) // Buat ambil node dari list l

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
{
	/* Mengirim true jika list kosong. Lihat definisi di atas. */
	return (FIRST(l) == NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
{
	/* I.S. l sembarang             */
	/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
	FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val)
{
	/* Mengirimkan Address hasil alokasi sebuah elemen */
	/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
	/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
	/* Jika alokasi gagal, mengirimkan NULL */
	Address P = (Address)malloc(sizeof(ElmtList));
	if (P != NULL)
	{
		INFO(P) = val;
		NEXT(P) = NULL;
	}
	return P;
}
void deallocate(Address P)
{
	/* I.S. P terdefinisi */
	/* F.S. P dikembalikan ke sistem */
	/* Melakukan dealokasi/pengembalian Address P */
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
{
	/* Mencari apakah ada elemen list dengan INFO(P)= val */
	/* Jika ada, mengirimkan Address elemen tersebut. */
	/* Jika tidak ada, mengirimkan NULL */
	if (isEmpty(l))
	{
		return NULL;
	}
	else
	{
		Address p = FIRST(l);
		boolean found = false;
		while (NEXT(p) != FIRST(l) && !found)
		{
			if (INFO(p) == val)
			{
				found = true;
			}
			else
			{
				p = NEXT(p);
			}
		}

		if (INFO(p) == val) // In case kalau cuman 1 elemen karena satu elemen ga masuk while
		{
			found = true;
		}

		if (found)
		{
			return p;
		}
		else
		{
			return NULL;
		}
	}
}

boolean addrSearch(List l, Address p)
{
	/* Mencari apakah ada elemen list l yang beralamat p */
	/* Mengirimkan true jika ada, false jika tidak ada */
	if (isEmpty(l))
	{
		return false;
	}
	else
	{
		Address q = FIRST(l);
		while (NEXT(q) != FIRST(l) && q != p)
		{
			q = NEXT(q);
		}
		return (q == p);
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
{
	/* I.S. l mungkin kosong */
	/* F.S. Melakukan alokasi sebuah elemen dan */
	/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
	Address q, p = allocate(val);
	if (p != NULL)
	{
		if (isEmpty(*l))
		{
			// Jika hanya satu element, maka nunjuk diri sendiri
			FIRST(*l) = p;
			NEXT(p) = p;
		}
		else
		{
			q = FIRST(*l);
			while (NEXT(q) != FIRST(*l)) // Geser ampe ke terakhir, karena insert first, biar yg paling akhir nunjuk ke p
			{
				q = NEXT(q);
			}
			NEXT(p) = FIRST(*l);
			NEXT(q) = p;
			FIRST(*l) = p;
		}
	}
}
void insertLast(List *l, ElType val)
{
	/* I.S. l mungkin kosong */
	/* F.S. Melakukan alokasi sebuah elemen dan */
	/* menambahkan elemen list di akhir: elemen terakhir yang baru */
	/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
	if (isEmpty(*l))
	{
		insertFirst(l, val);
	}
	else
	{
		Address q, p = allocate(val);
		if (p != NULL)
		{
			q = FIRST(*l);
			while (NEXT(q) != FIRST(*l))
			{
				q = NEXT(q);
			}
			NEXT(q) = p;
			NEXT(p) = FIRST(*l);
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
{
	/* I.S. List l tidak kosong  */
	/* F.S. val adalah elemen pertama list l sebelum penghapusan */
	/*      Elemen list berkurang satu (mungkin menjadi kosong) */
	/*      First element yg baru adalah suksesor elemen pertama yang lama */
	/*      Alamat elemen terakhir di-dealokasi */
	Address q, p = FIRST(*l);
	*val = INFO(p);			  // Ambil nilai dari node yang mau dihapus (yang pertama)
	if (NEXT(p) == FIRST(*l)) // in case hanya satu elemen dan jika node first elemen di list sama dengan next nodenya
	{
		FIRST(*l) = NULL;
	}
	else
	{
		q = FIRST(*l);
		while (NEXT(q) != FIRST(*l))
		{
			q = NEXT(q);
		}
		FIRST(*l) = NEXT(p); // Geser first ke nextnya
		NEXT(q) = FIRST(*l);
	}
	free(p);
}
void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. x adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen pertama yg lama, jika ada */
/*      Alamat elemen terakhir di-dealokasi */
{
	Address p = FIRST(*l);
	Address q = NULL;		  // tail pointer for p
	if (FIRST(*l) == NEXT(p)) // in case hanya satu elemen dan jika node first elemen di list sama dengan next nodenya
	{
		deleteFirst(l, val);
	}
	else
	{
		while (NEXT(p) != FIRST(*l))
		{
			q = p;
			p = NEXT(p);
		}
		*val = INFO(p);
		NEXT(q) = FIRST(*l);
		deallocate(p);
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
{
	/* I.S. List mungkin kosong */
	/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika list kosong : menulis [] */
	/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
	if (isEmpty(l))
	{
		printf("[]");
	}
	else
	{
		Address p = FIRST(l);
		printf("[");
		while (NEXT(p) != FIRST(l))
		{
			printf("%d,", INFO(p));
			p = NEXT(p);
		}
		printf("%d]", INFO(p));
	}
}

#endif