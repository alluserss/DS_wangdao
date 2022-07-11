/*
设一个二叉树中各结点的值互不相同
其先序遍历序列和中序遍历序列分别存于两个一维数组A,B中
试编写算法建立该二叉树的二叉链表
*/
#include <iostream>
using namespace std;
struct Binode{
    char data;
    Binode *lchild;
    Binode *rchild;
};

typedef Binode *Bitree;

int index=0;
Binode* node(char A[], char B[], int L, int R){
    if(L<=R){
        Binode *T= new Binode;
        T->data=A[index++];
        int i=L;
        for(;i<=R;++i)
            if(B[i]==T->data) break;
        T->lchild=node(A,B,L,i-1);
        T->rchild=node(A,B,i+1,R);
        return T;
    }
    return NULL;
}

void preOrder(Bitree T){
    if(T){
        cout<<T->data<<' ';
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

void inOrder(Bitree T){
    if(T){
        inOrder(T->lchild);
        cout<<T->data<<' ';
        inOrder(T->rchild);
    }
}

void postOrder(Bitree T){
    if(T){
        postOrder(T->lchild);
        postOrder(T->rchild);
        cout<<T->data<<' ';
    }
}

int main() {
    char A[]={'A','B','D','E','C','F','G'};    //先序遍历序列
    char B[]={'D','B','E','A','F','G','C'};    //中序遍历序列

    Bitree T;
    T=node(A,B,0,6);
    preOrder(T); cout<<endl;
    inOrder(T); cout<<endl;
    postOrder(T); cout<<endl;
}
