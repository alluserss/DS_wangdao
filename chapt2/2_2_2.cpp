/*
 * 在带头结点的单链表L中，
 * 删除所有值为x的结点，并释放其空间
 * 假设值为x的结点不唯一
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
int a[8]={1,2,3,4,5,6,5,7};
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

//删除值为x的结点
void Del_x(Llink &L, int x){
    Lnode *p=L->next, *pre=L, *q;   //p用来找x, pre指向p的前一个结点，q用来删除结点
    while (p!=NULL){
        if(p->data==x){
            q=p;
            pre->next=p->next;
            p=p->next;
            delete q;
        }
        else{
            p=p->next;
            pre=pre->next;
        }
    }
}

int main()
{
    Llink L;
    Init(L);
    Print(L);

    Del_x(L,5);
    Print(L);
    return 0;
}
