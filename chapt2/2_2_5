/*
 * 将带有头结点的单链表就地逆置
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
int a[8]={1,2,3,4,5,6,7,8};
int n=8;

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

//逆置，采用头插法
void Reverse_head(Llink &L){
    Lnode *p=L->next, *r;
    L->next=NULL;
    while (p!=NULL){
        r=p->next;
        p->next=L->next;
        L->next=p;
        p=r;
    }
}

int main()
{
    Llink L;
    Init(L);
    Print(L);

    Reverse_head(L);
    Print(L);
    return 0;
}
