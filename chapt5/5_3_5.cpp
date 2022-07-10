/*
非递归算法求二叉树高度
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

//利用层序遍历算法
int height(BiTree T){
    queue<Binode*>Q;
    int front=-1, rear=-1, last=0;  //rear指向当前入队的结点, last指向每层最右边的结点
    int h=0;
    Binode *p;
    Q.push(T);  ++rear;
    while(front<rear){
        p=Q.front(); ++front;
        Q.pop();
        if(p->lchild){
            Q.push(p->lchild); ++rear;
        }
        if(p->rchild){
            Q.push(p->rchild); ++rear;
        }
        if(front==last){
            ++h;
            last=rear;
        }
    }
    return h;
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

    cout<<"Height: "<<height(T)<<endl;
}
