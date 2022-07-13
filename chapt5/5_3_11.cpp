/*
对于树中每个元素值为x的结点，删去以它为根的子树，并释放相应的空间
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

//删除以X为根的全部树
void Delete_x(BiTree &T){
    if(T==NULL)return;  //如果为空返回
    Delete_x(T->lchild);//如果不为空，遍历左子树和右子树
    Delete_x(T->rchild);
    delete T;       //如果左子树和右子树都为空，删除根节点
}
//找到以X为根的结点，并调用Delete_X函数进行删除
void searchAndDelete(BiTree &T,char X){
    if(T==NULL) return;     //如果为空，返回
    if(T->data==X){     //如果不为空，且值为X。即找到，开始执行删除操作
        Delete_x(T);
        T=NULL; 
    }
    if(T!=NULL){
        searchAndDelete(T->lchild,X);   //如果不为空且不等于X，继续寻找左子树和右子树
        searchAndDelete(T->rchild,X);
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
    //InOrder(T); cout<<endl;

    searchAndDelete(T,'G');
    preOrder(T); cout<<endl;
    //InOrder(T); cout<<endl;
    
}
