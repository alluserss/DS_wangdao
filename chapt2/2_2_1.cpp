/*
 *设计一个递归算法，
 * 删除不带头结点的单链表L中
 * 所有值为x的结点
 */

#include <cstdio>
//不带头结点的链表

struct Linknode{
    int data;
    Linknode * next;
};

typedef Linknode Lnode,*Llink;

//打印一个链表
void Print(Llink L){
    while(L!=NULL){
        printf("%d ",L->data);
        L=L->next;
    }
    printf("\n");
}

//初始化一个链表
void Init(Llink &L){
    L = new Lnode;
    L->next = NULL;
    Lnode *r = L;
    int x;
    printf("Please enter a number: (-1 to end)");
    scanf("%d",&x);
    if(x!=-1){
        L->data=x;
    }
    else{
        printf("Error");
        return;
    }
    printf("Please enter a number: (-1 to end)");
    scanf("%d",&x);
    while(x!=-1){
        Lnode * temp = new Lnode;
        temp->data = x;
        temp->next = r->next;
        r->next = temp;
        r = temp;
        printf("Please enter a number: (-1 to end)");
        scanf("%d",&x);
    }

}

//递归，删除不带头结点的单链表L中所有值为x的结点
void Del_x(Llink &L,int x){
    if(L==NULL) return;     //递归出口
    if(L->data==x){
        Lnode *p = L;
        L=L->next;
        delete p;
        Del_x(L,x);
    }
    else{
        Del_x(L->next,x);
    }

}

int main()
{
    Llink L;
    Init(L);
    Print(L);
    Del_x(L,5);
    Print(L);
    return 0;
}
