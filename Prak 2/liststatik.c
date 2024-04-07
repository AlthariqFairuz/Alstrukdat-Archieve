/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include "boolean.h"
#include <stdio.h> 

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARK -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType;  /* type elemen List */
typedef int IdxType;
typedef struct {
   ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container), ini mendeklarasikan array contents dgn type Eltype dagn len sepanjang CAPACITY */
} ListStatik;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)] // Pakai titik karena l itu struct dan contents itu array dalam struct bukan array biasa sehingga harus pakai titik

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
   int i;
   for (i=0; i<CAPACITY; i++){
      ELMT(*l,i) = MARK;
   }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
   int i;
   i=0;
   while (ELMT(l,i) != MARK && i<CAPACITY){
      i++;
   }
   return i;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
   return IDX_MIN;
}
IdxType getLastIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
   return listLength(l)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
   return ((i>=IDX_MIN) && (i<CAPACITY));
}
boolean isIdxEff(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
   return ((i>=IDX_MIN) && (i<listLength(l)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
   return (listLength(l) == 0);
}
/* *** Test List penuh *** */
boolean isFull(ListStatik l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
   return(listLength(l) == CAPACITY);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
   int n;
   int i;
   scanf("%d", &n);
   while (n<0 || n>CAPACITY) {
      scanf("%d", &n);
   }
   CreateListStatik(l);
   if (n>0) {
      for(i=0; i<n;i++) {
         scanf("%d", &ELMT(*l,i));
      }
   }
   else {
      CreateListStatik(l);
   }
}
void printList(ListStatik l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
   int i;
   printf("[");
   if (listLength(l)>0){
      for (i=0;i<listLength(l)-1;i++){
         printf("%d,", ELMT(l,i));
      }
      printf("%d", ELMT(l,i));
   }
   printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
   ListStatik l3;
   CreateListStatik(&l3);
   int i;
   if (plus) {
      for (i=0;i<listLength(l1);i++){
         ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
      }
   }
   else {
      for (i=0;i<listLength(l1);i++){
         ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
      }
   }
   return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
   if (listLength(l1) == listLength(l2)){
      int i=0;
      while (i<listLength(l1)){
         if(ELMT(l1,i) != ELMT(l2,i)){
            return false;
         }
         i++;
      }
      return true;
   }
   return false;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
   int i;
   i=0;
   while (i<listLength(l) && ELMT(l,i) != val){
      i++;
   }
   if (ELMT(l,i) == val){
      return i;
   }
   else {
      return IDX_UNDEF;
   }
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
   int i;
   *max = ELMT(l,0);
   *min = ELMT(l,0);
   for (i=0;i<listLength(l);i++){
      if (ELMT(l,i) > *max){
         *max = ELMT(l,i);
      }
      if (ELMT(l,i) < *min){
         *min = ELMT(l,i);
      }
   }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx){
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
   int i;
   for (i = listLength(*l)-1; i>=idx; i--){
      ELMT(*l,i+1) = ELMT(*l,i);
   }
   ELMT(*l,idx) = val;
}

/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
   // int i;
   // if (listLength(*l) == 0){
   //    ELMT(*l,0) = val;
   // }
   // else {
   //    if(listLength(*l) != CAPACITY){
   //       for (i=listLength(*l); i>0;i--){
   //          ELMT(*l,i) = ELMT(*l,i-1); // Majuin elemennya
   //       }
   //       if (i == 0) {
   //          ELMT(*l,i) = val;
   //       }
   //    }
   // }
   insertAt(l,val,0);
}

/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
   // int i;
   // if (listLength(*l) == 0){
   //    ELMT(*l,0) = val;
   // }
   // else {
   //    ELMT(*l,listLength(*l)) = val;
   // }  
   insertAt(l,val,listLength(*l)); // gapake -1 akrena dia nambahin di belakang
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
   int i;
   *val = ELMT(*l, idx);
   for (i=idx; i<listLength(*l)-1; i++){
      ELMT(*l,i) = ELMT(*l,i+1);
   }
   ELMT(*l,listLength(*l)-1) = MARK;
}

/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
   deleteAt(l,val,0);

}
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
   deleteAt(l,val,listLength(*l)-1);
}

/* ********** SORTING ********** */

void sortList(ListStatik *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas = bubble sort */
   int i,j;
   ElType temp;
   if (asc){
      for (i=0;i<listLength(*l)-1;i++){
         for(j=0;j<listLength(*l)-1-i;j++){
            if(ELMT(*l,j) > ELMT(*l,j+1)){
               temp = ELMT(*l, j); // switch
               ELMT(*l, j) = ELMT(*l, j + 1);
               ELMT(*l, j + 1) = temp;
            }
         }
      }
   }
   else {
      for (i=0;i<listLength(*l)-1;i++){
         for(j=0;j<listLength(*l)-1-i;j++){
            if(ELMT(*l,j) < ELMT(*l,j+1)){
               temp = ELMT(*l, j); // switch
               ELMT(*l, j) = ELMT(*l, j + 1);
               ELMT(*l, j + 1) = temp;
            }
         }
      }
   }

}

#endif

