/*
设有一个带头结点的循环单链表，其结点值均为正整数
设计一个算法，反复找出单链表中结点值最小的结点并输出
然后将该结点从中删除，直到单链表空为止，
再删除头结点
*/
#include <cstdio>
//带头结点的循环单链表
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

//依次输出最小结点值并删除结点
void printMin(Llink &L){
    while (L->next!=L)
    {
        Lnode *pre=L, *p=L->next;    //p为工作指针
        Lnode *premin=L, *min=L->next;  //保存最小指针
        while (p!=L)
        {
            if(p->data<min->data){
                min=p;
                premin=pre;
            }
            p=p->next;
            pre=pre->next;
        }
        printf("%d ", min->data);
        premin->next=min->next;
        delete min;
    }
    delete L;
    printf("\n");
}

int main()
{
    Llink L;
    int a[]={13,2,6,9,1,5,21,7,8,10,-1};
    Init(L,a);
    Print(L);

    printMin(L);
    return 0;
}
