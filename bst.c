#include"basic.h"
#include"bst.h"

struct tnode{
    int key;
    struct tnode *Lchild;
    struct tnode *Rchild;
};

struct tnode *BTS_Insert(struct tnode *T, int key){
    if (T==NULL){
        struct tnode *p=(struct tnode *) malloc(sizeof(struct tnode));
        p->key=key; 
        p->Lchild=NULL;
        p->Rchild=NULL;
        return p; 
    }
    ///
    if (key - T->key<0) T->Lchild=BTS_Insert(T->Lchild, key);
    else T->Rchild =BTS_Insert(T->Rchild, key);

    return T;
}

struct tnode *BTS_find(struct tnode *T,  int  key){//
    if (T==NULL) return NULL;
    
    int c = key - T->key;
    
    if (c==0) return T;
    else if (c>0) {
        //printf("what?\n");
        return BTS_find(T->Rchild, key);
    }
    else return BTS_find(T->Lchild, key);
}
void traverse(struct tnode *T){
    if (T==NULL) return ;
    traverse(T->Lchild);
    printf("%d\n", T->key); 
    traverse(T->Rchild);
}
struct tnode*  Bbst(int *data, int iNum, struct tnode * tree){
    
            int i;
            for(i=0;i<iNum;i++){
                tree = BTS_Insert(tree, *(data+i) );
                
            }
                 
            //traverse(tree);//單純測建樹的時間而已就不走訪了了~
            return tree;
            
}
void Qbst(int *data , int qNum, struct tnode * tree){
            int i;
            int x[qNum];
            struct tnode * ori_tree = (struct tnode*) malloc(sizeof(struct tnode));
            for(i=0;i<qNum;i++){//找到給1 沒找到給0
                if(tree = BTS_find(tree, *(data+i)) ){
                   // printf("1\n");
                    x[i] = 1;
                    tree = ori_tree; //tree 會變NULL或找到的那個位置 要指回去才可以再找
                }
                else {
                   // printf("0\n"); 
                    x[i] =0;
                    tree = ori_tree;
                }              
            }
    
}
//void qbst(int *data, int ){}