/* File: datetime.h */
/* Tanggal: 30 Agustus 2023 */
/* Definisi ADT DATETIME */

#ifndef DATETIME_H
#define DATETIME_H

#include <stdio.h>
#include "boolean.h"
#include "time.h"


/* *** Definisi TYPE DATETIME <DD/MM/YY HH:MM:SS> *** */
typedef struct
{
    int DD;   /* integer [1..31] */
    int MM;   /* integer [1..12] */
    int YYYY; /* integer [1900..2030] */
    TIME T;
} DATETIME;

/* *** Notasi Akses: selektor DATETIME *** */
#define Day(D) (D).DD
#define Month(D) (D).MM
#define Year(D) (D).YYYY
#define Time(D) (D).T

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int GetMaxDay(int M, int Y){
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */

    if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12 ) {
        return 31;
    }

    else if (M == 4 || M == 6 || M == 9 || M == 11 ) {
        return 30;
    }
    else if (M == 2) {
        return 28;
    }
    else{
    if ((Y % 400 != 0) || (Y & 4 == 0) && (Y % 100 == 0)) {
            if (M == 2) {
                return 29;
            }
        } 
    }
}
boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s){
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */
    return ((D>=1 && D<=31) && (M>=1 && M<=12) && (Y>=1990 && Y<=2030) && (h>=0 && h<=23) && (m>=0 && m<=59) && (s>=0 && s<=59));
}

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss){
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    Hour(Time(*D)) = hh;
    Minute(Time(*D)) = mm;
    Second(Time(*D)) = ss;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D){
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
    diulangi hingga didapatkan DATETIME yang valid. */
/* Contoh:
    32 13 2023 12 34 56
    DATETIME tidak valid
    31 12 2023 12 34 56
    --> akan terbentuk DATETIME <31,12,2023,12,34,56> */
    scanf("%d %d %d %d %d %d", &Day(*D), &Month(*D), &Year(*D), &Hour(Time(*D)), &Minute(Time(*D)), &Second(Time(*D)));
    while (!IsDATETIMEValid(Day(*D), Month(*D), Year(*D), Hour(Time(*D)), Minute(Time(*D)), Second(Time(*D)))) {
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d %d %d %d", &Day(*D), &Month(*D), &Year(*D), &Hour(Time(*D)), &Minute(Time(*D)), &Second(Time(*D)));
    }
}

void TulisDATETIME(DATETIME D){
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
    printf("%d/%d/%d %d:%d:%d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2){
/* Mengirimkan true jika D1=D2, false jika tidak */
    return((Day(D1) == Day(D2)) && (Month(D1) == Month(D2)) && (Year(D1) == (Year(D2)))&& (Hour(Time(D1)) == Hour(Time(D2))) && (Minute(D1) ==  Minute(Time(D2))) && (Second(Time(D1)) == Second(Time(D2))));
}
boolean DNEQ(DATETIME D1, DATETIME D2){
/* Mengirimkan true jika D1 tidak sama dengan D2 */
    return !DEQ(D1,D2);
}
boolean DLT(DATETIME D1, DATETIME D2){
/* Mengirimkan true jika D1<D2, false jika tidak */
    return((Year(D1) < Year(D2)) || (Year(D1) == Year(D2)) && (Month(D1) < Month(D2)) || (Year(D1) == Year(D2)) && (Month(D1) == Month(D2)) && (Day(D1) < Day(D2)) || (Year(D1) == Year(D2)) && (Month(D1) == Month(D2)) && (Day(D1) == Day(D2)) && (Hour(Time(D1)) < Hour(Time(D2))) || (Year(D1) == Year(D2)) && (Month(D1) == Month(D2)) && (Day(D1) == Day(D2)) && (Hour(Time(D1)) == Hour(Time(D2))) && (Minute(D1) < Minute(Time(D2))) || (Year(D1) == Year(D2)) && (Month(D1) == Month(D2)) && (Day(D1) == Day(D2)) && (Hour(Time(D1)) == Hour(Time(D2))) && (Minute(D1) == Minute(Time(D2))) && (Second(Time(D1)) < Second(Time(D2))));
}
boolean DGT(DATETIME D1, DATETIME D2){
/* Mengirimkan true jika D1>D2, false jika tidak */
    return((Year(D1) > Year(D2)) || (Year(D1) == Year(D2)) && (Month(D1) > Month(D2)) || (Year(D1) == Year(D2)) && (Month(D1) == Month(D2)) && (Day(D1) > Day(D2)) || (Year(D1) == Year(D2)) && (Month(D1) == Month(D2)) && (Day(D1) == Day(D2)) && (Hour(Time(D1)) > Hour(Time(D2))) || (Year(D1) == Year(D2)) && (Month(D1) == Month(D2)) && (Day(D1) == Day(D2)) && (Hour(Time(D1)) == Hour(Time(D2))) && (Minute(D1) > Minute(Time(D2))) || (Year(D1) == Year(D2)) && (Month(D1) == Month(D2)) && (Day(D1) == Day(D2)) && (Hour(Time(D1)) == Hour(Time(D2))) && (Minute(D1) == Minute(Time(D2))) && (Second(Time(D1)) > Second(Time(D2))));
}
DATETIME DATETIMENextNDetik(DATETIME D, int N){
/* Mengirim salinan D dengan detik ditambah N */
    DATETIME newDate = D;
    Second(Time(newDate)) += N;
    while (Second(Time(newDate)) >= 60) {
        Second(Time(newDate)) -= 60;
        Minute(Time(newDate)) +=1;
    }
    while (Minute(Time(newDate)) >= 60){
        Minute(Time(newDate)) -= 60;
        Hour(Time(newDate)) += 1;
    }
    while(Hour(Time(newDate))>=24) {
        Hour(Time(newDate)) -= 24;
        Day(newDate) += 1;
        if (Day(newDate)> GetMaxDay(Month(newDate), Year(newDate))){
            Day(newDate) = 1;
            Month(newDate) ++;
            if(Month(newDate) > 12){
                Month(newDate) = 1;
                Year(newDate) ++;
            }
        }
    }
    return newDate;
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
/* Mengirim salinan D dengan detik dikurang N */
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
DATETIME newDate = D;
    Second(Time(newDate)) -= N;
    while (Second(Time(newDate)) < 60) {
        Second(Time(newDate)) += 60;
        Minute(Time(newDate)) --;
    }
    while (Minute(Time(newDate)) < 60){
        Minute(Time(newDate)) += 60;
        Hour(Time(newDate)) --;
    }
    while(Hour(Time(newDate)) <0) {
        Hour(Time(newDate)) += 24;
        Day(newDate) --;
        if (Day(newDate)< 1){
            Month(newDate) --;
            if(Month(newDate) < 1){
                Month(newDate) = 12;
                Year(newDate) --;
            }
            Day(newDate) = GetMaxDay(Month(newDate), Year(newDate)); // Ambil hari max berdasarkan bulan yg baru jika terjadi pergantian bulan 
        }
    }
    return newDate;
}
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh){
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */
    long int durasi, detik1 ,detik2;
    detik1 = Year(DAw)*31536000+ Month(DAw)*2592000 + Day(DAw)*86400 + Hour(Time(DAw))*3600 + Minute(Time(DAw))*60 + Second(Time(DAw));
    detik2 = Year(DAkh)*31536000+ Month(DAkh)*2592000 + Day(DAkh)*86400 + Hour(Time(DAkh))*3600 + Minute(Time(DAkh))*60 + Second(Time(DAkh));
    return detik2-detik1;
}

#endif