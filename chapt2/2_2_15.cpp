/*
A、B是两个带头结点的单链表，其中元素递增有序
求A与B的交集并放于A链表中
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

void findSame(Llink &A, Llink &B){
    Lnode *p=A->next, *q=B->next;
    A->next=NULL;
    Lnode *pre=A;
    while (p!=NULL && q!=NULL)
    {
        if(p->data<q->data){
            Lnode *tmp=p;
            p=p->next;
            delete tmp;
        }
        else if(p->data>q->data){
            Lnode *tmp=q;
            q=q->next;
            delete tmp;
        }
        else{
            Lnode *r=new Lnode;
            r->data=p->data;
            r->next=pre->next;
            pre->next=r;
            pre=r;

            Lnode *tmp1=p, *tmp2=q;
            p=p->next;
            q=q->next;
            delete tmp1;
            delete tmp2;
        }
    }

    //删除长的链表的剩余元素
    if(p!=NULL) q=p;
    while (q!=NULL)
    {
        Lnode *tmp=q;
        q=q->next;
        delete tmp;
    }
    delete B;
    
}

int main()
{
    Llink A, B;
    int a[]={1,3,6,8,10,16,27,-1};
    int b[]={2,3,4,5,6,7,8,9,10,14,16,20,-1};
    Init(A,a);
    Init(B,b);
    Print(A);
    Print(B);

    findSame(A,B);
    Print(A);
 
    return 0;
}
