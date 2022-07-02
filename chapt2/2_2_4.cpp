/*
 * 在带头结点的单链表中删除一个最小结点
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
int a[8]={5,6,7,9,11,2,4,3};
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

//找到最小结点并删除
void Del_min(Llink &L){
    Lnode *p=L->next, *pre=L, *l=pre, *r=p; //用p遍历，pre指向p的前驱；r保持最小结点、l保存最小结点的前驱
    while (p!=NULL){
        if(p->data<r->data){   //更新最小结点
            r=p;
            l=pre;
        }
        p=p->next;
        pre=pre->next;
    }
    //删除最小结点
    l->next = r->next;
    delete r;
}

int main()
{
    Llink L;
    Init(L);
    Print(L);

    Del_min(L);
    Print(L);
    return 0;
}
