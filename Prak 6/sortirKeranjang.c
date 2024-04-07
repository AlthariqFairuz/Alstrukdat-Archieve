#include "stack.h"
#include <stdio.h>

void SortirKeranjang (Stack * S1, Stack * S2)

{

    infotype x, y, swap;
    int Array[MaxEl];
    int j = 0;


    if (IsEmpty(*S1)) {
        return;
    }

    while (!IsEmpty(*S1)) {
        Pop(S1, &x);
        Array[j] = x;
        j++;
    }

    for (x = 0; x < j; x++) {
        for (y = x + 1; y < j; y++) {
            if (Array[x] < Array[y]) {
                swap = Array[x];
                Array[x] = Array[y];
                Array[y] = swap;
            }
        }
    }

    for (x = 0; x < j; x++) {
        Push(S2, Array[x]);
    }
}
