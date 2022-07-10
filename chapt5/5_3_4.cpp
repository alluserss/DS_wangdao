/*
二叉树自下而上、从右到左的层次遍历算法
*/
#include <iostream>
#include<stack>
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

//利用层次遍历算法，再利用一个栈使得反向层次遍历
void levelOrderReverse(BiTree T){
    queue<Binode*>Q;
    stack<Binode*>S;
    Binode *p=T;
    Q.push(p);  //根结点入队
    while(!Q.empty()){  //队列不空
        p=Q.front();
        Q.pop();
        S.push(p);
        
        if(p->lchild)   //左子树不为空，左子树根结点入队
            Q.push(p->lchild);
        if(p->rchild)   //右子树不为空，右子树根节点入队
            Q.push(p->rchild);
    }
    while(!S.empty()){
        cout<<S.top()->data<<' ';
        S.pop();
    }
    cout<<endl;
}

int main() {
    /*创建的二叉树为
         A
       B   C
      D E F G
      ABD##E##CF##G##
    */
    BiTree T;
    preCreate(T);

    preOrder(T); cout<<endl;

    levelOrderReverse(T);
}
