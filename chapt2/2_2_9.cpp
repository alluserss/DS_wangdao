/*
给定一个带表头结点的单链表
按递增次序输出单链表中各结点的数据元素
并释放结点所占的存储空间（要求不允许使用数组作为辅助空间）
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

//每找到一个最小的，输出并删除结点
void Printout(Llink &L){
    while (L->next!=NULL)
    {
        Lnode *p=L->next, *pre=L;   //p遍历，pre保存最小结点的前一个结点
        while (p->next!=NULL)     //找每次循环的最小结点
        {
            if(p->next->data<pre->next->data)
                pre=p;
            p=p->next;
        }
        //删除最小结点并输出值
        printf("%d ",pre->next->data);
        Lnode *tmp = pre->next;
        pre->next = tmp->next;
        delete tmp;
    }
    
}

int main()
{
    Llink L;
    Init(L);
    Print(L);
    
    Printout(L);
    return 0;
}
