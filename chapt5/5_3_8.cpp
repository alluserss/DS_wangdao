/*
设计一个算法，计算一颗给定二叉树的所有双分支结点个数
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
int n=0;
//在前序遍历中加入判断
//递归前序遍历
void preOrder(BiTree T){
    if(T!=NULL){
        cout<<T->data<<' ';
        if(T->lchild&&T->rchild) ++n;
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

//也可以单独写一个遍历函数
int num(BiTree T){
    if(T==NULL) return 0;
    else if(T->lchild&&T->rchild) return num(T->lchild)+num(T->rchild)+1;
    else return num(T->lchild)+num(T->rchild);
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
    cout<<"双分支结点个数为: "<<n<<endl;
    cout<<num(T)<<endl;
    
}
