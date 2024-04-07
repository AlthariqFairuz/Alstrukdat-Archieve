#include "merge.h"
#include <stdio.h>
#include "listlinier.h"
#include "boolean.h"

void splitList(List source, List* front, List* back) {
/* Fungsi untuk memecah sebuah list dengan head source menjadi dua buah 
   list baru, yaitu front dan back. Apabila panjang list ganjil, maka
   list front akan lebih panjang dibandingkan list back.
   Sebagai contoh untuk list dengan panjang 5, maka list front memiliki
   3 elemen dan list back memiliki 2 elemen.
*/

    int len = length(source), i, val;
    if (len%2 == 0) { // if the members are even
        for (i = 0; i < len / 2; i++) {
            val = getElmt(source, i);
            insertLast(front, val);
        }

        for (i = (len/2); i < len; i++) {
            val = getElmt(source, i);
            insertLast(back, val);
        }
    } else { // if odd
        len = (len + 1);
        for (i = 0; i < len / 2; i++) {
            val = getElmt(source, i);
            insertLast(front, val);
        }

        for (i = (len/2); i < len - 1; i++) {
            val = getElmt(source, i);
            insertLast(back, val);
        }
    }
}

List merge(List a, List b) {
/* Fungsi untuk melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
   Apabila List a = NULL, maka kembalikan List b
   Apabila List b = NULL, maka kembalikan List a
   Selain itu, lakukan perbandingan antara INFO(a) dengan 
   INFO(b) untuk mendapatkan urutannya
*/
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }

    List l3;
    Address p;
    ElType val;
    CreateList(&l3);

    // insert a in order
    int idx, idxA;
    for (idxA = 0; idxA < length(a); idxA++) {
        val =  getElmt(a, idxA);
        p = l3;
        for (idx = 0; idx < length(l3); idx++) {
            if (INFO(p) > val) {
                insertAt(&l3, val, idx);
                break;
            }
            p = NEXT(p);
        }
        if (idx == length(l3)) {
            insertLast(&l3, val);
        }
    }

    // insert b in order
    int idxB;
    for (idxB = 0; idxB < length(b); idxB++) {
        val =  getElmt(b, idxB);
        p = l3;
        for (idx = 0; idx < length(l3); idx++) {
            if (INFO(p) > val) {
                insertAt(&l3, val, idx);
                break;
            }
            p = NEXT(p);
        }
        if (idx == length(l3)) {
            insertLast(&l3, val);
        }
    }

    return l3;
}

void mergeSort(List* list) {
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Setiap kali fungsi dipanggil, maka tampilkan list yang sekarang
   sedang diproses.
   Apabila head atau NEXT(head) kosong, maka lakukan return
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian 
   secara rekursif melakukan merge untuk mengurutkan
*/
    List lFront, lBack;

    displayList(*list);
    printf("\n");
    CreateList(&lFront); CreateList(&lBack);

    splitList(*list, &lFront, &lBack);
    if (lFront == NULL || lBack == NULL) {
        return;
    } else {
        mergeSort(&lFront);
        mergeSort(&lBack);
        *list = merge(lFront, lBack);
    }
}
