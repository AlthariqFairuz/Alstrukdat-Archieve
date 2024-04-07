#include "queue.h"
#include <stdio.h>

int main()
{
    Queue queue;
    int operation, value, served = 0;
    float average;
    boolean isActive;
    CreateQueue(&queue);
    isActive = true;
    while (isActive)
    {
        scanf("%d", &operation);
        if (operation == 1)
        {
            scanf("%d", &value);
            if (isFull(queue))
            {
                printf("Queue penuh\n");
            }
            else
            {
                enqueue(&queue, value);
            }
        }
        else if (operation == 2)
        {
            if (isEmpty(queue))
            {
                printf("Queue kosong\n");
            }
            else
            {
                // dequeue
                dequeue(&queue, &value);
                served++;
                average += value;
            }
        }
        else
        {
            isActive = false;
        }
    }

    // output result
    printf("%d\n", served);
    if (served != 0)
    {
        printf("%.2f\n", (float)average / served);
    }
    else
    {
        printf("Tidak bisa dihitung\n");
    }
    return 0;
}
