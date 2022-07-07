/*
设计一个算法用于判断带头结点的循环双链表是否对称
*/

#include <cstdio>
//带头结点的循环双链表
struct Linknode{
    int data;
    Linknode * prior;
    Linknode * next;
};

typedef Linknode Lnode,*Llink;

//打印一个链表
void Print(Llink L){

    if(L->next==L && L->prior==L){
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
    L->prior = L;
    Lnode *r = L;
    while (*a!=-1)      //数组以-1结束作为标志
    {
        Lnode * temp = new Lnode;
        temp->data = *a;
        temp->next = r->next;
        temp->prior = r;
        r->next = temp;
        L->prior = temp;    //头结点前驱指向插入的结点
        r = temp;
        a++;
    }
}

bool isSym(const Llink L){
    Lnode *p=L->next, *q=L->prior;    //分别从头和尾开始比较
    if(p==q) return false;
    while (p!=q && q->next!=p)  //奇数(同时指向中间),偶数(两指针错过终止)列终止条件
    {
        if(p->data!=q->data) return false;
        else{
            p=p->next;
            q=q->prior;
        }
    }
    return true;
}

int main()
{
    Llink A, B, C;
    int a[]={1,2,3,6,8,10,11,12,10,8,6,3,1,-1};
    int b[]={1,3,5,7,9,7,5,3,1,-1};     //奇数序列
    int c[]={2,4,6,8,8,6,4,2,-1};       //偶数序列
    Init(A,a); Init(B,b); Init(C,c);
    Print(A); Print(B); Print(C);

    if(isSym(A)) printf("A对称\n");
    else printf("A不对称\n");
    if(isSym(B)) printf("B对称\n");
    else printf("B不对称\n");
    if(isSym(C)) printf("C对称\n");
    else printf("C不对称\n");

    return 0;
}
