/*
一个带头结点的单链表中所有元素结点的数据值无序
编写一个函数，删除表中所有介于给定的两个值（作为函数参数给出）
之间的元素的元素
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

//删除给定值之间的元素
void Del_ab(Llink &L, int a, int b){
    if(L->next==NULL || (a>=b))
        return;
    Lnode *p=L->next, *pre=L;
    while (p!=NULL)
    {
        if(p->data>a && p->data<b){
            Lnode * tmp=p;
            p=p->next;
            pre->next=tmp->next;
            delete tmp;
        }
        pre=pre->next;
        p=p->next;
    }
}

int main()
{
    Llink L;
    Init(L);
    Print(L);
    Del_ab(L,1,6);
    Print(L);
    return 0;
}
