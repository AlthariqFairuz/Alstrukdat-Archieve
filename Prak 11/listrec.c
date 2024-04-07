#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

/* Manajemen Memori */
Address newNode(ElType x) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
    Address new = (Address) malloc(sizeof(Node));
    if (new != NULL) {
        INFO(new) = x;
        NEXT(new) = NULL;
    }
    return new;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l) {
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
    return (l == NIL);
}

boolean isOneElmt(List l) {
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
    if (isEmpty(l)) {
        return false;
    } else {
        return (NEXT(l) == NIL);
    }
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l) {
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
    return INFO(l);
}

List tail(List l) {
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
    return NEXT(l);
}

List konso(List l, ElType e) {
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu.
   Jika alokasi gagal, mengirimkan l */
    Address new = newNode(e);
    if (new != NULL) {
        NEXT(new) = l;
        l = new;
    }
    return l;
}

List konsb(List l, ElType e) {
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

List copy(List l) {
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2) {
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */
    if (isEmpty(l1)) {
        return copy(l2);
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }

}

/* Fungsi dan Prosedur Lain */
int length(List l) {
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }

}

boolean isMember(List l, ElType x) {
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
    if (isEmpty(l)) {
        return false;
    } else {
        if (head(l) == x) {
            return true;
        } else {
            return isMember(tail(l), x);
        }
    }
}

void displayList(List l) {
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
    if (isEmpty(l)) {
        return;
    } else {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}


List insertAt(List l, ElType e, int idx) {
    List l2;
    l2 = NIL;
    while (idx > 0) {
        l2 = konsb(l2,head(l));
        l = tail(l);
        idx -= 1;
    }
    l = konso(l,e);
    l = concat(l2,l);
    return l;
}

List deleteFirst(List l) {
/* Fungsi untuk menghapus elemen pertama sebuah list l */
    l = tail(l);
    return l;
}

List deleteAt(List l, int idx) {
    List l2;
    l2 = NIL;
    while (idx > 0) {
        l2 = konsb(l2,head(l));
        l = tail(l);
        idx -= 1;
    }
    l = tail(l);
    l = concat(l2,l);
    return l;
}

List deleteLast(List l) {
/* Fungsi untuk menghapus elemen pada posisi/index idx sebuah list l */
    List l2;
    l2 = NIL;
    int panjang;
    for (panjang = length(l); panjang > 1; panjang--) {
        l2 = konsb(l2,head(l));
        l = tail(l);
    }
    return l2;
}
List inverseList (List l) {
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
    List l2;
    l2 = NIL;
    int panjang = length(l);
    for (int i = 0; i < panjang; i++) {
        l2 = konso(l2,head(l));
        l = tail(l);
    }
    return l2;
}

void splitPosNeg (List l, List *l1, List *l2) {
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */
    *l1 =NULL;
    *l2 = NULL;
    while (isEmpty(l) == false) {
        if (head(l) >= 0) {
            *l1 = konsb(*l1, head(l));
        }
        else {
            *l2 = konsb(*l2,head(l));
        }
        l = tail(l);
    }
}

void splitOnX (List l, ElType x, List *l1, List *l2) {
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */
    *l1 =NULL;
    *l2 = NULL;
    while (isEmpty(l) == false) {
        if (head(l) < x) {
            *l1 = konsb(*l1, head(l));
        }
        else {
            *l2 = konsb(*l2,head(l));
        }
        l = tail(l);
    }
}

List removeDuplicate(List l, List unique) {
    List l2;
    l2 = NULL;
    while (!isEmpty(l)) {
        if(!isMember(l2,head(l))) {
            l2 = konso(l2,head(l));
        }
        l = tail(l);
    }
    return l2;

}

