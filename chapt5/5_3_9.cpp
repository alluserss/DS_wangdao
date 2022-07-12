/*
B为链式结构存储的二叉树
编写一个将B中所有结点的左右子树进行交换的函数
*/
#include <iostream>
#include<queue>
using namespace std;

struct Binode{
    char data;
    Binode *lchild;
    Binode *rchild;
};

typedef Binode *BiTree;

//前序创建一个二叉树
void preCreate(BiTree &T){
    char ch;
    ch=getchar();
    if(ch=='#') T=NULL;
    else{
        T = new Binode;
        T->data=ch;
        T->lchild=NULL;
        T->rchild=NULL;
        preCreate(T->lchild);
        preCreate(T->rchild);
    }
}

//递归前序遍历
void preOrder(BiTree T){
    if(T!=NULL){
        cout<<T->data<<' ';
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

//递归中序遍历
void InOrder(BiTree T){
    if(T){
        InOrder(T->lchild);
        cout<<T->data<<' ';
        InOrder(T->rchild);
    }
}

//交换所有结点的左右子树
void Change(BiTree &T){
    if(T){
        Binode *tmp=T->lchild;
        T->lchild=T->rchild;
        T->rchild=tmp;
        Change(T->lchild);
        Change(T->rchild);
    }
}

int main() {
    /*创建的二叉树为
         A
       B   C
      D E F G
             H
      ABD##E##CF##G#H##
    */
    BiTree T;
    preCreate(T);

    preOrder(T); cout<<endl;
    InOrder(T); cout<<endl;

    Change(T);
    preOrder(T); cout<<endl;
    InOrder(T); cout<<endl;
}
