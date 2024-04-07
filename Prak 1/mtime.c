#ifndef MTIME_H
#define MTIME_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "time.h"

int main () {

    int n,i;
    long durasi;;
    TIME time_MIN,time_MAX,t1,t2;

    Hour(time_MIN)= 23;
    Minute(time_MIN)= 59;
    Second(time_MIN) = 59;
    Hour(time_MAX)= 0;
    Minute(time_MAX)= 0;
    Second(time_MAX) = 0;

    scanf("%d",&n);
    for (i=1;i<=n;i++){
        printf("[%d]\n",i);
        BacaTIME(&t1);
        BacaTIME(&t2);
        if (TIMEToDetik(t1) <= TIMEToDetik(time_MIN)) {
            time_MIN = t1;
        }
        if (TIMEToDetik(t2) <= TIMEToDetik(time_MIN)) {
            time_MIN = t2;
        }
        if (TIMEToDetik(t2) >= TIMEToDetik(time_MAX)) {
            time_MAX = t2;
        }
        if (TIMEToDetik(t1) >= TIMEToDetik(time_MAX)) {
            time_MAX = t1;
        }

        if (TLT(t1,t2)){
            durasi= Durasi(t1,t2);
        }
        else {
            durasi= Durasi(t2,t1);
        }
        printf("%ld\n",durasi);
    }
    TulisTIME(time_MIN);
    printf("\n");
    TulisTIME(time_MAX);
    printf("\n");
    return 0;
}
#endif // MTIME_H
