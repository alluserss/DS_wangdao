/*
将一个带头结点的单链表A分解为两个带头结点的单链表A和B，
A含有序号为奇数的元素、B含有序号为偶数的元素
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

//将A拆分成奇数A和偶数B

void change(Llink &A, Llink &B){
    Lnode *p=A->next, *pre=A, *q=B;
    int i=1;        
    while (p!=NULL)
    {   
        if(i%2==0){   //偶数元素
            Lnode * r=p;
            pre->next=p->next;
            p=p->next;
            r->next=q->next;
            q->next=r;
            q=r;
        } 
        else{
            p=p->next;
            pre=pre->next;
        }
        i++;
    }
    
}


int main()
{
    Llink A;
    Init(A);
    Print(A);

    Llink B=new Lnode;
    B->next = NULL;
    
    change(A,B);

    Print(A);
    Print(B);
    return 0;
}
