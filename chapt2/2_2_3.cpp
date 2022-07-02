/*
 * 设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值
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
int a[8]={1,2,3,4,5,6,7,8};
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

//从尾到头反向输出每个结点的值
void print_reverse(Llink L){    //如果传入头结点，会读取头结点的内容，所以应传入头结点的下一个结点
    if(L->next==NULL) printf("%d ",L->data);
    else{
        print_reverse(L->next);
        printf("%d ",L->data);
    }
}

void Ignore_head(Llink L){
    if(L->next!=NULL) print_reverse(L->next);
}

int main()
{
    Llink L;
    Init(L);
    Print(L);

    Ignore_head(L);

    return 0;
}
