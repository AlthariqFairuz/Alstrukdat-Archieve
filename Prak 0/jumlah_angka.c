#include <stdlib.h>
#include <stdio.h>

int main(){
    int angka;
    int jumlah=0;
    scanf("%d", &angka);
    while (angka>0) {
        jumlah += angka%10;
        angka/=10;
    }
    printf("%d\n",jumlah);
    return 0;
}
