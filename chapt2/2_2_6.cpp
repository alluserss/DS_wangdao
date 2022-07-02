/*
 * 带头结点的单链表，使元素递增有序
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
int a[8]={6,2,8,4,7,1,3,9};
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

//递增, 将结点一个一个重新插入
void sort_(Llink &L){
    Lnode *p=L->next, *r=p->next, *pre; //r保存p后面的结点防止断链，pre找插入位置的前一个结点
    p->next=NULL;   //先插入一个，防止后面while判断pre->next->data出问题
    p=r;
    while (p!=NULL){
        r=p->next;
        pre=L;
        while (pre->next!=NULL && pre->next->data<p->data)
            pre=pre->next;
        p->next=pre->next;
        pre->next=p;
        p=r;
    }
}

int main()
{
    Llink L;
    Init(L);
    Print(L);
    sort_(L);
    Print(L);
    return 0;
}
