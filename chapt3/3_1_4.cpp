/*
判断链表的全部n个字符是否中心对称
*/

#include <cstdio>

struct Linknode{
    char data;
    Linknode * next;
};
typedef Linknode Lnode, *Llist;

//char chs[5]={'x','y','y','x','\0'};
//int n = 4;

char chs[4]={'x','y','x','\0'};
int n=3;

void Init(Llist &L){
    L = new Lnode;
    Lnode * r=L;
    for(int i=0;i<n;++i){
        Lnode *tmp = new Lnode;
        tmp->data = chs[i];
        r->next = tmp;
        r=tmp;
    }
    r->next = NULL;
}

//判断链表字符是否中心对称
bool isRegular(Llist L){
    char s[n/2]={};   //栈，存放链表前n/2个元素
    Lnode * r = L->next;
    int i=0;
    for(; i<n/2;++i){
        s[i] = r->data;
        r = r->next;
    }
    if(n%2!=0) r=r->next;
    i--;

    while (r!=NULL)
    {
        if(r->data!=s[i]) return false;
        r=r->next;
        i--;
    }
    return true; 
}

int main() {
    Llist L;
    Init(L);
    bool flag=isRegular(L);
    if(flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}
