#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>

boolean ELMT1(Matrix M)
{
    boolean apakah1semua = true;
    for (int i = 0; i < ROW_EFF(M); i++)
    {
        for (int j = 0; j < COL_EFF(M); j++)
        {
            if (ELMT(M, i, j) != 1)
            {
                apakah1semua = false;
                break;
            }
        }
    }
    return apakah1semua;
}

int main()
{
    int N, M, K;
    Matrix a;
    boolean *bisaselesai;

    scanf("%d %d", &N, &M);
    readMatrix(&a, N, M);
    scanf("%d", &K);

    bisaselesai = (boolean *)malloc(K * sizeof(boolean));

    for (int k = 0; k < K; k++)
    {
        boolean bisaselesai_k = false;

        Matrix subm;
        Matrix subm01;
        int A, B;
        scanf("%d %d", &A, &B);
        readMatrix(&subm, A, B);
        createMatrix(A, B, &subm01);

        int i = 0;
        while (i < ((N - A) + 1))
        {
            int j = 0;
            while (j < ((M - B) + 1))
            {

                for (int p = 0; p < A; p++)
                {
                    for (int q = 0; q < B; q++)
                    {
                        if (ELMT(subm, p, q) == ELMT(a, i + p, j + q))
                        {
                            ELMT(subm01, p, q) = 1;
                        }
                        else
                        {
                            ELMT(subm01, p, q) = 0;
                        }
                    }
                }

                if (ELMT1(subm01) == true)
                {
                    bisaselesai_k = true;
                    i = 101;
                    j = 101;
                }
                j++;
            }
            i++;
        }
        bisaselesai[k] = bisaselesai_k;
    }

    boolean apakahselesaisemua = true;
    for (int k = 0; k < K; k++)
    {
        if (bisaselesai[k] == false)
        {
            apakahselesaisemua = false;
            break;
        }
    }

    if (apakahselesaisemua == true)
    {
        printf("Puzzle dapat diselesaikan.\n");
    }
    else
    {
        printf("Puzzle tidak dapat diselesaikan.\n");
    }

    free(bisaselesai);

    return 0;
}
