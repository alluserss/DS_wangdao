/*
有两个循环链表，链表头指针分别为h1和h2
编写一个函数将链表h2链接到链表h1之后
要求链接后的链表仍保持循环链表形式
*/

#include <cstdio>
//带头结点的循环链表
struct Linknode{
    int data;
    Linknode * next;
};

typedef Linknode Lnode,*Llink;

//打印一个链表
void Print(Llink L){
    if(L->next==L){
        printf("It's none!");
        return;
    }
    Lnode *r=L->next;
    while(r!=L){
        printf("%d ",r->data);
        r=r->next;
    }
    printf("\n");
}


//初始化一个链表
void Init(Llink &L,int *a){ 
    L = new Lnode;
    L->next = L;
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

void Add(Llink &h1, Llink &h2){
    Lnode *p=h1, *q=h2;
    while (p->next!=h1) //找h1的尾结点
        p=p->next;
    while (q->next!=h2) //找h2的尾结点
        q=q->next;  
    q->next=h1;
    p->next=h2->next;
    delete h2;
}

int main()
{
    Llink h1, h2;
    int a[]={1,3,6,8,10,16,27,-1};
    int b[]={2,3,4,5,6,7,8,9,10,14,16,20,-1};
    Init(h1,a);
    Init(h2,b);
    Print(h1);
    Print(h2);

    Add(h1,h2);
    Print(h1);
 
    return 0;
}
