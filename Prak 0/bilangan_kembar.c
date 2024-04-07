#include <stdlib.h>
#include <stdio.h>

int main() {
    int start;
    int end;
    int i;
    int currentValue;
    int marker;
    int count;
    scanf("%d", &start);
    scanf("%d", &end);
    for (i=start;i<=end;i++) {
        currentValue=i;
        marker=i%10;
        while (currentValue % 10 == marker) {
            currentValue/=10;
            if (currentValue==0){
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;

}
