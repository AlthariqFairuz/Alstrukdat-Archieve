#include <stdio.h>
#include "queue.h"

int main()
{
    Queue q;
    int n, k, val, idx = 0;
    int i, j;
    int array[CAPACITY];

    CreateQueue(&q);
    scanf("%d", &n);
    scanf("%d", &k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        if (i < k)
        {
            array[i] = val;
            idx = i;
            continue;
        }
        if (i == k)
        {
            for (j = idx; j > -1; j--)
            {
                enqueue(&q, array[j]);
            }
        }
        enqueue(&q, val);
    }
    if (i == k)
    {
        for (j = idx; j > -1; j--)
        {
            enqueue(&q, array[j]);
        }
    }
    displayQueue(q);

    return 0;
}