/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __WORDMACHINE_H__
#define __WORDMACHINE_H__

#include "boolean.h"
#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>

#define NMax 50
#define BLANK ' '
typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
boolean EndWord;
Word currentWord;
boolean EOP;
char currentChar;

void IgnoreBlanks()
{
   /* Mengabaikan satu atau beberapa BLANK
      I.S. : currentChar sembarang
      F.S. : currentChar ≠ BLANK atau currentChar = MARK */
   while ((currentChar == BLANK) && ((currentChar != MARK)))
   {
      ADV();
   }
}

void CopyWord()
{
   /* Mengakuisisi kata, menyimpan dalam currentWord
      I.S. : currentChar adalah karakter pertama dari kata
      F.S. : currentWord berisi kata yang sudah diakuisisi;
             currentChar = BLANK atau currentChar = MARK;
             currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
             Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
   int i = 0;
   while (currentChar != MARK && currentChar != BLANK && i < NMax)
   {
      currentWord.TabWord[i] = currentChar;
      i++;
      ADV();
   }
   currentWord.Length = i;
}

void STARTWORD()
{
   /* I.S. : currentChar sembarang
      F.S. : EndWord = true, dan currentChar = MARK;
             atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
             currentChar karakter pertama sesudah karakter terakhir kata */
   START();
   IgnoreBlanks();
   if ((currentChar == MARK))
   {
      EndWord = true;
   }
   else
   {
      EndWord = false;
      CopyWord();
   }
}

void ADVWORD()
{
   /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
      F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
             currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
             Jika currentChar = MARK, EndWord = true.
      Proses : Akuisisi kata menggunakan procedure SalinWord */
   IgnoreBlanks();
   if ((currentChar == MARK))
   {
      EndWord = true;
   }
   else
   {
      CopyWord();
      IgnoreBlanks();
   }
}

#endif