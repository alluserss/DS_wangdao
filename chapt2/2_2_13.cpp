/*
有两个按元素值递增排序的线性表，以单链表形式存储
编写算法将这两个单链表归并为一个按元素值递减次序排列的单链表
并要求利用原来两个单链表的结点存放归并后的单链表
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


//初始化一个链表
void Init(Llink &L,int *a){ 
    L = new Lnode;
    L->next = NULL;
    Lnode *r = L;
    while (*a!=-1)      //数组以-1结束作为标志
    {
        Lnode * temp = new Lnode;
        temp->data = *a;
        temp->next = r->next;
        r->next = temp;
        r = temp;
        a++;
    }
}

//合并两个有序表
void Add(Llink &A, Llink &B){
    Lnode *p = A->next, *q=B->next;
    A->next=NULL;   //新表的头结点
    while (p!=NULL && q!=NULL)
    {
        if(p->data<q->data){    //采用头插法，依次插入较小的结点
            Lnode *r=p->next;
            p->next=A->next;
            A->next=p;
            p=r;
        }
        else
        {
            Lnode *r=q->next;
            q->next=A->next;
            A->next=q;
            q=r;    
        }
        
    }
    //将长的表内剩下元素插入
    if(p==NULL)
        p=q;
    while (p!=NULL)
    {
        Lnode *r=p->next;
        p->next=A->next;
        A->next=p;
        p=r;
    }
    delete p;
}


int main()
{
    Llink A, B;
    int a[]={1,3,6,8,10,16,27,-1};
    int b[]={2,4,5,7,12,14,20,22,23,25,-1};
    Init(A,a);
    Init(B,b);
    Print(A);
    Print(B);

    Add(A,B);
    Print(A);
    return 0;
}
