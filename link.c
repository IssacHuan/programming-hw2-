#include"basic.h"
#include"link.h"


struct node{
        int key;
        struct node *p; 
    };

struct node *insert(struct node *top, int num) {
    
    struct node* New = (struct node*)malloc(sizeof(struct node));
    New->key = num;
    New->p = top->p;
    top->p = New;  

    return top;
}

struct node *Bll(int *data1, int iNum , struct node* head ){   
    int i;
    head->p = NULL;

    for(i=0;i<iNum;i++){
        head = insert(head, *(data1+i));
    }
    return head;
}

void Qll(int * data2, int qNum, struct node *top){
    int i=0;
    int x[qNum];
    top = top->p;//因為第一個是頭 沒放東西
    while(i<qNum){
        while(top!=NULL){
            if(top->key == *(data2+i)){
                x[i] = 1; //找到就放1
                break;
            }
            top = top->p;          
        }
        i++;
    }
}
