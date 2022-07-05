/*
A、B是两个带头结点的单链表，其中元素递增有序
从A、B的公共元素产生单链表C
要求不破坏A、B的结点
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

Llink addSame(const Llink A, const Llink B){
    //建立新链表
    Llink C=new Lnode;
    C->next=NULL;
    Lnode *r=C; //用于存储插入结点的前驱结点

    Lnode *p=A->next, *q=B->next;   //用于遍历A,B
    while (p!=NULL,q!=NULL)
    {
        if(p->data<q->data)
            p=p->next;
        else if(p->data>q->data)
            q=q->next;
        else{
            Lnode *tmp = new Lnode;
            tmp->data=p->data;
            tmp->next=r->next;
            r->next=tmp;
            r=tmp;
            p=p->next;
            q=q->next;
        }
    }
    return C;
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

    Llink C=addSame(A,B);
    Print(C);
    
    return 0;
}
