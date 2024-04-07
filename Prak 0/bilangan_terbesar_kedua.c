#include <stdlib.h>
#include <stdio.h>

int main(){
    int n;
    int max1=0;
    int max2=0;
    int i=0;
    scanf("%d", &n);
    int array[n];
    while (i<n) {
        scanf("%d", &array[i]);
        i++;
    }

    for (i=0;i<=n;i++){
        if (array[i]>=max1){
            max1=array[i];
        }
    }

    for (i=0;i<=n;i++){
        if (array[i]>=max2 && array[i] != max1){
                max2=array[i];
        }
    }
    printf("%d\n",max2);
    return 0;
}

/*
Alternative ver

    for (int i = 0; i < n; i++){
        if (array[i] > max1){
            max2 = max1;
            max1 = array[i];
        } else if (array[i] > max2 && array[i] != max1) {
            max2 = array[i];
        }
    }

*/
