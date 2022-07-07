/*
两个整数序列A、B存入两个单链表，
设计一个算法判断：
B是否是A的连续子序列
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

//判断B是否是A的连续子序列
bool isChild(const Llink A,const  Llink B){
    Lnode *pre=A->next, *p=A->next, *q=B->next;
    while (p!=NULL && q!=NULL)
    {
        if(p->data==q->data){   //依次比较两个序列的数
            p=p->next;
            q=q->next;
        }
        else{   //如果不相等, 从开始比较的下一个数开始重新比较
            pre=pre->next;
            p=pre;
            q=B->next;
        }
    }
    if(q==NULL) return true;
    else return false;
}

int main()
{
    Llink A, B;
    int a[]={1,2,3,6,8,10,11,12,9,10,11,12,13,14,16,27,-1};
    int b[]={10,11,12,13,14,-1};
    Init(A,a);
    Init(B,b);
    Print(A);
    Print(B);
    if(isChild(A,B)) printf("B是A的子序列\n");
    else printf("B不是A的子序列\n");
 
    return 0;
}
