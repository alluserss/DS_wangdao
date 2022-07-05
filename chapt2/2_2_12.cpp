/*
在一个递增有序的线性表中，删除数值相同的元素
*/

#include <cstdio>
//带头结点的链表
struct Linknode{
    int data;
    Linknode * next;
};

typedef Linknode Lnode,*Llink;

//打印一个链表
void Print(Llink L){
    if(L==NULL){
        printf("It's none!");
        return;
    }
    L=L->next;
    while(L!=NULL){
        printf("%d ",L->data);
        L=L->next;
    }
    printf("\n");
}

//为方便起见，设置一个数组，直接将数组元素赋给链表
int a[10]={7,10,10,21,30,42,42,42,51,70};
int n=10;

//初始化一个链表
void Init(Llink &L){
    L = new Lnode;
    L->next = NULL;
    Lnode *r = L;
    for(int i=0; i<n; ++i){
        Lnode * temp = new Lnode;
        temp->data = a[i];
        temp->next = r->next;
        r->next = temp;
        r = temp;
    }
}

//删除重复元素
void Del(Llink &L){
    Lnode *p=L->next, *pre=L;
    if(p==NULL) return;
    
    while (p->next!=NULL)
    {
        if(p->next->data==p->data){ //重复，删除p结点
            Lnode *r=p;
            pre->next=p->next;
            p=p->next;
            delete r;
        }
        else{
            pre=pre->next;
            p=p->next;
        }
    }
}


int main()
{
    Llink A;
    Init(A);
    Print(A);
   
    Del(A);
    Print(A);
    
    return 0;
}
