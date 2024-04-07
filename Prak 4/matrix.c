/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType; /* Index baris, kolom */
typedef int ElType;
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
{
   /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
   /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
   /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
   ROW_EFF(*m) = nRows;
   COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
{
   /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
   return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
{
   /* Mengirimkan Index baris terbesar m */
   return (ROW_EFF(m) - 1);
}
IdxType getLastIdxCol(Matrix m)
{
   /* Mengirimkan Index kolom terbesar m */
   return (COL_EFF(m) - 1);
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j)
{
   /* Mengirimkan true jika i, j adalah Index efektif bagi m */
   return ((i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m)));
}
ElType getElmtDiagonal(Matrix m, IdxType i)
{
   /* Mengirimkan elemen m(i,i) */
   return (ELMT(m, i, i));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
{
   /* Melakukan assignment mOut <- mIn */
   int i, j;
   createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);

   for (i = 0; i < ROW_EFF(mIn); i++)
   {

      for (j = 0; j < COL_EFF(mIn); j++)
      {

         ELMT(*mOut, i, j) = ELMT(mIn, i, j);
      }
   }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
{
   /* I.S. isIdxValid(nRow,nCol) */
   /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
   /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
   /* Selanjutnya membaca nilai elemen per baris dan kolom */
   /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
   1 2 3
   4 5 6
   8 9 10
   */
   int i, j;
   createMatrix(nRow, nCol, m);

   for (i = 0; i < nRow; i++)
   {

      for (j = 0; j < nCol; j++)
      {

         scanf("%d", &ELMT(*m, i, j));
      }
   }
}

void displayMatrix(Matrix m)
{
   /* I.S. m terdefinisi */
   /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
      dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
   /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
   /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
   1 2 3
   4 5 6
   8 9 10
   */
   int i, j;

   for (i = 0; i < ROW_EFF(m); i++)
   {
      for (j = 0; j < COL_EFF(m) - 1; j++)
      {
         printf("%d ", ELMT(m, i, j));
      }
      printf("%d", ELMT(m, i, COL_EFF(m) - 1));
      printf("\n");
   }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
{
   /* Prekondisi : m1 berukuran sama dengan m2 */
   /* Mengirim hasil penjumlahan matriks: m1 + m2 */
   Matrix m3;
   int i, j;
   createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);

   for (i = 0; i < ROW_EFF(m1); i++)
   {
      for (j = 0; j < COL_EFF(m1); j++)
      {
         ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
      }
   }
   return m3;
}

Matrix subtractMatrix(Matrix m1, Matrix m2)
{
   /* Prekondisi : m1 berukuran sama dengan m2 */
   /* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
   Matrix m3;
   int i, j;
   createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);

   for (i = 0; i < ROW_EFF(m1); i++)
   {
      for (j = 0; j < COL_EFF(m1); j++)
      {
         ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
      }
   }
   return m3;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
   /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
   /* Mengirim hasil perkalian matriks: salinan m1 * m2 */
   /* Misal 3X4 4X5, maka matrix baru harus 3X5*/
   Matrix m3;
   int i, j, k;
   createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);

   for (i = 0; i <= ROW_EFF(m1); i++)
   {
      for (j = 0; j <= COL_EFF(m2); j++)
      {
         ELMT(m3, i, j) = 0; // inisialisasi nilai 0 utk matrix hasil perkalian
         for (k = 0; k <= COL_EFF(m1); k++)
         {
            ELMT(m3, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
         }
      }
   }
   return m3;
}

Matrix multiplyByConst(Matrix m, ElType x)
{
   /* Mengirim hasil perkalian setiap elemen m dengan x */
   Matrix temp;
   int i, j;
   createMatrix(ROW_EFF(m), COL_EFF(m), &temp);
   for (i = 0; i < ROW_EFF(m); i++)
   {
      for (j = 0; j < COL_EFF(m); j++)
      {
         ELMT(temp, i, j) = ELMT(m, i, j) * x;
      }
   }
   return temp;
}

Matrix multiplyMatrixWithMod(Matrix m1, Matrix m2, int mod)
{
   /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
   /* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
   Matrix m3;
   int i, j;

   createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
   m3 = multiplyMatrix(m1, m2);

   for (i = 0; i < ROW_EFF(m3); i++)
   {
      for (j = 0; j < COL_EFF(m3); j++)
      {
         ELMT(m3, i, j) %= mod;
      }
   }
   return m3;
}
void pMultiplyByConst(Matrix *m, ElType k)
{
   /* I.S. m terdefinisi, k terdefinisi */
   /* F.S. Mengalikan setiap elemen m dengan k */
   int i, j;
   for (i = 0; i < ROW_EFF(*m); i++)
   {
      for (j = 0; j < COL_EFF(*m); j++)
      {
         ELMT(*m, i, j) *= k;
      }
   }
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
{
   /* Mengirimkan banyaknya elemen m */
   return (ROW_EFF(m) * COL_EFF(m));
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
   /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
   /* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
   return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}
boolean isMatrixEqual(Matrix m1, Matrix m2)
{
   /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
   /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
   /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
   int i = 0, j = 0;

   if ((ROW_EFF(m1) != ROW_EFF(m2)) || (COL_EFF(m1) != COL_EFF(m2)))
   {
      return false;
   }

   for (i; i < ROW_EFF(m1); i++)
   {
      for (j; j < COL_EFF(m1); j++)
      {
         if (ELMT(m1, i, j) != ELMT(m2, i, j))
         {
            return false;
         }
      }
   }
   return true;
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
   /* Mengirimkan true jika m1 tidak sama dengan m2 */
   return (!isMatrixEqual(m1, m2));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
{
   /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
   return (ROW_EFF(m) == COL_EFF(m));
}
boolean isSymmetric(Matrix m)
{
   /* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
      dan untuk setiap elemen m, m(i,j)=m(j,i) */
   int i = 0, j = 0;
   if (!isSquare(m))
   {
      return false;
   }
   for (i; i < ROW_EFF(m); i++)
   {
      for (j; j < COL_EFF(m); j++)
      {
         if (ELMT(m, i, j) != ELMT(m, j, i))
         {
            return false;
         }
      }
   }
   return true;
}
boolean isIdentity(Matrix m)
{
   /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
      setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
   if (!isSquare(m))
   {
      return false;
   }
   int i = 0, j = 0;
   for (i; i < ROW_EFF(m); i++)
   {
      for (j; j < COL_EFF(m); j++)
      {
         if (i == j)
         {
            if (ELMT(m, i, j) != 1)
            {
               return false;
            }
         }
         else
         {
            if (ELMT(m, i, j) != 0)
            {
               return false;
            }
         }
      }
   }
   return true;
}
boolean isSparse(Matrix m)
{
   /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
      hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
   int i = 0, j = 0, count = 0;
   for (i; i < ROW_EFF(m); i++)
   {
      for (j; j < COL_EFF(m); j++)
      {
         if (ELMT(m, i, j) != 0)
         {
            count++;
         }
      }
   }
   return (count <= (0.05 * countElmt(m)));
}
Matrix negation(Matrix m)
{
   /* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
   return multiplyByConst(m, (-1));
}
void pNegation(Matrix *m)
{
   /* I.S. m terdefinisi */
   /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
   pMultiplyByConst(m, (-1));
}

float determinant(Matrix m)
{
   /* Prekondisi: isSquare(m) */
   /* Menghitung nilai determinan m */
   int i, j, k, var = 1, d;
   float det;
   Matrix coFac;

   if (countElmt(m) == 1)
   { // matrix 1x1
      det = (float)ELMT(m, 0, 0);
   }
   else if (countElmt(m) == 4)
   { // matrix 2x2
      det = (ELMT(m, 0, 0) * ELMT(m, 1, 1)) - (ELMT(m, 0, 1) * ELMT(m, 1, 0));
      det = (float)(det);
   }
   else
   { // matrix nxn, diisni digunakan metode kofaktor dengan baris 1 (index row =0) sbg basisnya
      createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &coFac);
      det = 0;
      for (i = 0; i < ROW_EFF(m); i++)
      {
         for (j = 1; j < ROW_EFF(m); j++)
         { // j dari 1 karena klu kofaktor pasti pake baris sebelahnya
            for (k = 0; k < COL_EFF(m); k++)
            {
               // abaikan baris yg sama dgn kolom dan baris yg dipakai sebagai basis, akrena itu aturannya di kofaktor
               if (k == i)
               {
                  continue;
               }
               else if (k < i)
               {
                  // d adalah index pada matrix cofactor, kenapa d=k? misal matrix 3x3, saati di kolom idx ke 1, maka ia pasti pake kolom idx 0 dan idx 2 yg mana k bernilai 0 dan k<i saat itu dengan i =1
                  d = k;
               }
               else
               {
                  // kenapa k-1? karena klu k<i, maka d = k, tapi klu k>i, maka d = k-1, contohnya saat udah nyentuh kolom terakhir, maka kita selalu gunakan kolom sebelumnya
                  d = k - 1;
               }
               ELMT(coFac, j - 1, d) = ELMT(m, j, k); // j-1 karena index matrix cofactor selalu berkurang 1
            }
         }
         det += var * ELMT(m, 0, i) * determinant(coFac);
         var *= -1; // minus plus selang seling di cofactor
      }
   }
   return det;
}

Matrix transpose(Matrix m)
{
   /* I.S. m terdefinisi dan IsSquare(m) */
   /* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
   Matrix temp;
   int i, j;
   createMatrix(COL_EFF(m), ROW_EFF(m), &temp);
   for (i = 0; i < COL_EFF(m); i++)
   {
      for (j = 0; j < ROW_EFF(m); j++)
      {
         ELMT(temp, i, j) = ELMT(m, j, i);
      }
   }
   return temp;
}
void pTranspose(Matrix *m)
{
   /* I.S. m terdefinisi dan IsSquare(m) */
   /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
   Matrix temp;
   temp = transpose(*m); // *&m = m
   copyMatrix(temp, m);  // karena mOut harus berupa pointer(adress) inputnya, maka kita ga perlu nambah pointer lagi di copyMatrix
}

#endif