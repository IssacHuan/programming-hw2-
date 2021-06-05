#include"basic.h"
#include"bs.h"

int cmp(const void * a, const void * b){
    return (*(int*)a - *(int*)b);
}

int *Bbs(int* data1, int inum){
    int i ;
    int arr[inum];
    int * ori_arr;
    ori_arr = arr;
    for(i=0;i<inum;i++){
        arr[i] = *(data1+i);
    }
    qsort(arr, inum, sizeof(int) , cmp);
    return ori_arr;
}

void Qbs(int *data2, int qNum  , int *arr, int iNum  ){
    int low = 0, high = iNum - 1, middle;
    int x[qNum] ;
    int i;
    for(i=0; i<qNum; i++){
        x[qNum] = 0; //一開始都是0
        while( high >= low ){
            middle = (high + low) / 2;
            if(*(arr+middle) == *(data2+i)){
                x[i] =1; //找到放1
                break;
            }
            else if(arr[middle] > *(data2+i))
                high = middle - 1;
            else
                low = middle + 1;
        }
    }
    return;
}