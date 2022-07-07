/*
头指针为L的带有表头结点的非循环双向链表，其每个结点除有pred、data和next外
还有一个访问频度域freq，初始化为0
每当链表中进行一次Locate(L,x)运算时，元素值为x的结点中的freq增1
并使此链表中结点保持按访问频度非增的顺序排列，最近访问的结点排在频度相同结点的前面
Locate(L,x)返回找到结点的地址，类型为指针型
*/
#include <cstdio>

//带头结点的非循环双向链表
struct Linknode{
    int data;
    Linknode * next;
    Linknode * pred;
    int freq;
};

typedef Linknode Lnode,*Llink;

//打印一个链表
void Print(Llink L){
    if(L->next==NULL){
        printf("It's none!");
        return;
    }
    L=L->next;
    while(L!=NULL){
        printf("%d(%d) ",L->data,L->freq);
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
        temp->freq = 0;
        temp->next = r->next;
        temp->pred = r;
        r->next = temp;
        r = temp;
        a++;
    }
}

Lnode* Locate(Llink &L, int x){
    Lnode *p=L->next;
    //找到x结点并使freq增1
    while (p!=NULL && p->data!=x)
        p=p->next;
    if(p==NULL) return NULL;
    p->freq++;
    
    //将x结点按频度插入前面
    Lnode *q=p->pred;
    while (q!=L && q->freq<=p->freq)
        q=q->pred;
    p->pred->next=p->next;
    if(p->next!=NULL)
        p->next->pred=p->pred;
    
    q->next->pred=p;
    p->next=q->next;
    p->pred=q;
    q->next=p;

    return p;
}

int main()
{
    Llink A;
    int a[]={1,3,6,8,10,16,27,-1};
    Init(A,a);
    Print(A);

    Lnode *tmp1 = Locate(A,27);
    Lnode *tmp2 = Locate(A,16);
    Lnode *tmp3 = Locate(A,10);
    Lnode *tmp4 = Locate(A,6);
    Lnode *tmp5 = Locate(A,10);
    Lnode *tmp6 = Locate(A,3);
    Lnode *tmp7 = Locate(A,3);

    Print(A);
    return 0;
}
