#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"
#include "garis.h"

void jarak() {
    int b,n,i,yangSelamat;
    GARIS serigala;
    float jarak;
    i=0;
    yangSelamat=0;


    scanf("%d", &b);
    BacaGARIS(&serigala);
    scanf("%d", &n);
    
    while (i<n) {
        POINT biribiri;
        BacaPOINT(&biribiri);
        jarak = JarakGARIS(serigala,biribiri);
        if (jarak <= b) {
            yangSelamat++;
        }
        i++;
    }
    printf("%d\n", yangSelamat);

}

int main () {
    jarak();
    return 0;
}