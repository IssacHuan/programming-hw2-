#include"basic.h"
#include"bst.h"
#include"arr.h"
#include"bs.h"
#include"link.h"
struct tnode{
    int key;
    struct tnode *Lchild;
    struct tnode *Rchild;
};
struct node{
        int key;
        struct node *p; 
    };

int main (int argc, char **argv ){
    long int iNum;
    long int qNum;
    int number;
    FILE *xfile;
    FILE *yfile;
    struct timeval start;//起始點
	struct timeval end;//結束點
	unsigned long diff;//儲存計算的時間差
    
    /*char way[5][5] ;
    strcpy(way[0],"-bst");
    strcpy(way[1],"-bs");
    strcpy(way[2],"-arr");
    strcpy(way[3],"-ll");
    strcpy(way[4],"-hash");
*/
    
    if(strcmp(argv[1], "-d")==0){
        iNum = atoi(argv[2]) ;
    }
    if(strcmp(argv[3], "-q")==0){
        qNum = atoi(argv[4]) ;
    }
    int i;
    
    srand(10);
    int *data1 = malloc(sizeof(int)*iNum);
    for(i = 0; i < iNum; i ++)
    { 
        *(data1+i) = rand() ;
    }
    
    int *data2 = malloc(sizeof(int)*iNum);
    
    for(i = 0; i < iNum; i ++)
    { 
        *(data2+i) = rand() ;
    }

    int  j = 5;
    while(j<=argc-1){
        if(strcmp(argv[j],"-bst")==0){
            struct tnode *tree=(struct tnode *) malloc(sizeof(struct tnode));
            tree = NULL;
            printf("bst:\n");
            
            gettimeofday(&start, NULL);//開始
            tree = Bbst(data1, iNum, tree);
            //traverse(tree);
            gettimeofday(&end, NULL);//結束
            
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	        printf("building time: %lf sec\n", diff / 1000000.0);//印出結果
            

            gettimeofday(&start, NULL);//開始
            Qbst(data2,qNum, tree);
            gettimeofday(&end, NULL);//結束
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	        printf("query time: %lf sec\n", diff / 1000000.0);//印出結果
            j++;
            continue;

        }
        else if(strcmp(argv[j],"-arr")==0){
            int *arr = (int*)malloc(sizeof(int));
            printf("arr:\n");
            gettimeofday(&start, NULL);//開始
            arr = Barr(data1, iNum);
            //traverse(tree);
            gettimeofday(&end, NULL);//結束          
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	        printf("building time: %lf sec\n", diff / 1000000.0);//印出結果
            

            gettimeofday(&start, NULL);//開始
            Qarr(data2, qNum , arr, iNum  );
            gettimeofday(&end, NULL);//結束
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	        printf("query time: %lf sec\n", diff / 1000000.0);//印出結果
            free(arr);
            j++;
            continue;

        }
        else if(strcmp(argv[j],"-bs")==0){
            int *bsarr= (int*)malloc(sizeof(int)) ;
            printf("bs:\n");
            gettimeofday(&start, NULL);//開始
            bsarr = Bbs(data1, iNum);
            //traverse(tree);
            gettimeofday(&end, NULL);//結束          
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	        printf("building time: %lf sec\n", diff / 1000000.0);//印出結果
            

            gettimeofday(&start, NULL);//開始
            Qarr(data2, qNum , bsarr, iNum  );
            gettimeofday(&end, NULL);//結束
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	        printf("query time: %lf sec\n", diff / 1000000.0);//印出結果
            free(bsarr);
            j++;
            continue;

        }
        
        else if(strcmp(argv[j],"-ll")==0){
            struct node *top=(struct node *) malloc(sizeof(struct node));
            printf("ll:\n");
            
            gettimeofday(&start, NULL);//開始
            top = Bll(data1, iNum, top);
            gettimeofday(&end, NULL);//結束
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	        printf("building time: %lf sec\n", diff / 1000000.0);//印出結果
            

            gettimeofday(&start, NULL);//開始
            Qll(data2,qNum, top);
            gettimeofday(&end, NULL);//結束
            diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	        printf("query time: %lf sec\n", diff / 1000000.0);//印出結果
            j++;
            continue;

        }
        else if(strcmp(argv[j],"-hash")==0){
            j++;
            continue;

        }
        
        

    }
  
        

    
}