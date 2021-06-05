#include"arr.h"
#include"basic.h"

int * Barr(int *data1, int inum){
    int i ;
    int arr[inum];
    int * ori_arr;
    ori_arr = arr;
    for(i=0;i<inum;i++){
        arr[i] = *(data1+i);
    }
    return ori_arr;
}

void Qarr(int *data2, int qnum, int *arr , int inum  ){
    int i,j;
    int x[qnum];
    for(i=0;i<qnum;i++){//printf("ggg\n");
        for(j=0;j<inum;j++){
            if(*(arr+j)==*(data2+j)) {
                x[i] = 1;
                break; 
            }
            else{
                x[i] = 0;
                break;
            } 
        }
    }
}