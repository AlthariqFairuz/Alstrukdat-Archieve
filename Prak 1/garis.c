/* File: garis.h */
/* Tanggal: 1 September 2023 */
/* Definisi ADT GARIS, menggunakan ADT point */
#ifndef GARIS_H
#define GARIS_H

/* *** ADT LAIN YANG DIPAKAI *** */
#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"

/* *** Definisi TYPE GARIS *** */
typedef struct {
  POINT PAw;  /* Titik Awal  */
  POINT PAkh; /* Titik Akhir */
} GARIS;

/* *** Selektor GARIS *** */
#define PAwal(L) (L).PAw
#define PAkhir(L) (L).PAkh

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void CreateGaris (GARIS * L, POINT P1, POINT P2){
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L) {
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat
   membentuk GARIS yang valid
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan:
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */

   POINT p1,p2;
   BacaPOINT(&p1);
   BacaPOINT(&p2);
   while(EQ(p1,p2)) {
        printf("Garis tidak valid\n");
        BacaPOINT(&p1);
        BacaPOINT(&p2);
   }
   CreateGaris(L,p1,p2);
}

void TulisGARIS (GARIS L){
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))"
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
    printf("((%.2f,%.2f),(%.2f,%.2f))", Absis(PAwal(L)),Ordinat(PAwal(L)),Absis(PAkhir(L)),Ordinat(PAkhir(L)));
}

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L){
/* Menghitung panjang garis L : berikan rumusnya : sqrt(pow(X2-x1)+(pow(y2-y1)))*/
    return Panjang (PAwal(L),PAkhir(L));
}

float Gradien (GARIS L){
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
    return ((Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))- Absis(PAwal(L))));
}
void GeserGARIS (GARIS * L, float deltaX, float deltaY){
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
    Absis(PAwal(*L)) = Absis(PAwal(*L)) + deltaX;
    Absis(PAkhir(*L)) = Absis(PAkhir(*L)) + deltaX;
    Ordinat(PAwal(*L)) = Ordinat(PAwal(*L)) + deltaY;
    Ordinat(PAkhir(*L)) = Ordinat(PAkhir(*L)) + deltaY;
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2){
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
    float m1,m2;
    m1 = Gradien(L1);
    m2 = Gradien(L2);
    return (m1*m2==-1);
}
boolean IsSejajar (GARIS L1, GARIS L2){
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
    float m1,m2;
        m1 = Gradien(L1);
        m2 = Gradien(L2);
        return (m1==m2);
}

/* *** Kelompok operasi garis dan point *** */
float JarakGARIS (GARIS L, POINT P){
/* Menghasilkan jarak terdekat antara titik P dan garis L */
/* Bentuklah persamaan dari garis L menjadi ax + by + c = 0 */
/* Jarak terdekat dari titik P ke garis L dapat didefinisikan sebagai d = |a * x + b * y + c| / akar kuadrat dari a * a + b * b */
    float a,b,c;
    a = Gradien(L);
    b = -1; // nilai Y
    c = (-1*a)* Absis(PAwal(L)) + Ordinat(PAwal(L));
    return (fabs(a*Absis(P) + b*Ordinat(P) + c) / sqrt(a*a + b*b));
}


boolean IsPointMemenuhiGaris (GARIS L, POINT P){
/* Menghasilkan true jika  titik P terletak di garis L */
/* Bentuklah persamaan dari garis L menjadi ax + by + c = 0 */
/* Titik P terletak di garis L jika dan hanya jika P memenuhi persamaan garis L, yaitu ax + by + c = 0 */
 float a,b,c;
    a = Gradien(L);
    b = -1; // nilai Y
    c = (-1*a)* Absis(PAwal(L)) + Ordinat(PAwal(L));
    return ((fabs(a*Absis(P) + b*Ordinat(P) + c) == 0)); // Kalau di dalam garis, maka jaraknya haruslah 0
}

#endif
