#ifndef POINT_H
#define POINT_H

#include "boolean.h"
#include <stdio.h>
#include <math.h>

const float PI = 3.141592653589793238462643;

typedef struct POINTS {
	float X; /* absis   */
	float Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define PI 3.14159265358979323846

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT * P, float X, float Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P) {
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    float x,y;
    scanf("%f %f", &x, &y);
    CreatePoint(P,x,y);
}

void TulisPOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}
boolean NEQ (POINT P1, POINT P2) {
/* Mengirimkan true jika P1 tidak sama dengan P2 */
    return (Absis(P1) != Absis(P2) && Ordinat(P1) != Ordinat(P2));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
/* Menghasilkan true jika P adalah titik origin */
    return (Absis(P) == 0 && Ordinat(P) == 0);
}
boolean IsOnSbX (POINT P){
/* Menghasilkan true jika P terletak Pada sumbu X */
    return(Ordinat(P) ==0);
}
boolean IsOnSbY (POINT P){
/* Menghasilkan true jika P terletak pada sumbu Y */
    return(Absis(P) ==0);
}
int Kuadran (POINT P){
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
    if (Absis(P) > 0 && Ordinat(P) > 0) {
        return 1;
    }
    else if (Absis(P) < 0 && Ordinat(P) > 0) {
        return 2;
    }
    else if (Absis(P) < 0 && Ordinat(P) < 0) {
        return 3;
    }
    else {
        return 4;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
/* Mengirim salinan P dengan absis ditambah satu */
    POINT pt;
    CreatePoint(&pt,Absis(P)+1,Ordinat(P));
    return (pt);
}
POINT NextY (POINT P){
/* Mengirim salinan P dengan ordinat ditambah satu */
    POINT pt;
    CreatePoint(&pt,Absis(P),Ordinat(P)+1);
    return (pt);
}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    POINT pt;
    CreatePoint(&pt,Absis(P)+deltaX,Ordinat(P)+deltaY);
    return (pt);
}
POINT MirrorOf (POINT P, boolean SbX){
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
    if (SbX == true) {
        POINT pt;
        CreatePoint(&pt,Absis(P),0-Ordinat(P));
        return pt;
    }
    else {
        POINT pt;
        CreatePoint(&pt,0-Absis(P),Ordinat(P));
        return pt;
    }
}
float Jarak0 (POINT P){
/* Menghitung jarak P ke (0,0) */
    return (float)(sqrt(Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P)));
}

float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
    float dx = Absis(P2) - Absis(P1);
    float dy = Ordinat(P2) - Ordinat(P1);
    return (float) (sqrt(dx * dx + dy * dy));
}

void Geser (POINT *P, float deltaX, float deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P){
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P){
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
    if (SbX == true) {
        CreatePoint(P,Absis(*P),0-Ordinat(*P));
    }
    else {
        POINT pt;
        CreatePoint(P,0-Absis(*P),Ordinat(*P));
    }
}

void Putar (POINT *P, float Sudut){
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
    float radian = -Sudut * PI/180;
    float newX = (Absis(*P) * cos(radian)) - (Ordinat(*P) * sin(radian));
    float newY = (Absis(*P) * sin(radian)) + (Ordinat(*P) * cos(radian));

    Absis(*P) = newX;
    Ordinat(*P) = newY;
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
/* I.S. P1 dan P2 terdefinisi */
/* Prekondisi: dijamin a dan b merupaka bilangan bertipe integer */
/* F.S. Dibentuk sebuah persamaan garis y = ax + b yang memenuhi untuk P1 dan P2 */
/* Keluarkan nilai a dan b */
/* Output a dan b tercetak di layar sebagai bilangan bertipe integer dengan format "(a,b)" */
    float a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    float b =  Ordinat(P1) - a * Absis(P1);

    printf("(%d,%d)", (int) a,(int) b);
}

#endif