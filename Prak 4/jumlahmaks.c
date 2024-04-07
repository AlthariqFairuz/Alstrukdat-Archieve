#include <stdio.h>
#include "matrix.h"

int main()
{
    int N, M, K;
    Matrix m;
    scanf("%d %d %d", &N, &M, &K);
    readMatrix(&m, N, M);

    int now_sum = 0;
    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= K; j++)
        {

            if ((i * j == K) && (i <= N) && (j <= M))
            {
                for (int k = 0; k < (N - i) + 1; k++)
                {
                    for (int l = 0; l < (M - j) + 1; l++)
                    {

                        int sum = 0;
                        for (int p = 0; p < i; p++)
                        {
                            for (int q = 0; q < j; q++)
                            {
                                sum += ELMT(m, k + p, l + q);
                            }
                        }

                        if (sum > now_sum)
                        {
                            now_sum = sum;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", now_sum);

    return 0;
}