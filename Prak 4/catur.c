#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

int main() {
    Matrix catur;
    int i,j,black=0,white=0;
    readMatrix(&catur,8,8);
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){

            if ((i==j)){
                if (ELMT(catur,i,j)==1){
                    black++;
                }
            }

            else if ((i%2==0 && j%2==0)||((i%2==1)&&(j%2==1))){
                if (ELMT(catur,i,j)==1){
                    black++;
                }
            }

            else if ((i%2==1 && j%2==0)||(i%2==0 && j%2==1)){
                if(ELMT(catur,i,j)==1){
                white++;
                }
            }    

    }
    }
    printf("%d %d\n", black , white);
    return 0;
}