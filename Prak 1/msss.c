#include <stdio.h>
#include "math.h"
#include "point.h"

int main()
{
    POINT P1, P2, P3;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    BacaPOINT(&P3);

    int a, b, c;
    c = ((Ordinat(P3) - Ordinat(P1)) - (((Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1)))) * (Absis(P3) - Absis(P1))) / ((Absis(P3) * Absis(P3) - Absis(P1) * Absis(P1)) - (Absis(P3) - Absis(P1)) * (Absis(P2) + Absis(P1)));
    b = ((Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1))) - c * (Absis(P2) + Absis(P1));
    a = Ordinat(P1) - b * Absis(P1) - c * Absis(P1) * Absis(P1);

    printf("%d\n", a);

    return 0;
}