/*
求先序遍历序列中第k个结点的值
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

int i=1;
char ch;
//先序遍历找到第k个结点
char Find_k(BiTree T, int k){
    if(T==NULL) return '#';
    if(i==k) return T->data;
    i++;
    ch=Find_k(T->lchild,k);
    if(ch!='#') return ch;  //找到，直接返回
    ch=Find_k(T->rchild,k);
    return ch;
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
    
    //cout<<Find_k(T,3)<<endl;
    //cout<<Find_k(T,6)<<endl;
    //cout<<Find_k(T,7)<<endl;
    cout<<Find_k(T,8)<<endl;
}
