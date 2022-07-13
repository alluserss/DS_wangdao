/*
查找值为x的结点，打印它的所有祖先
假设值为x的结点不多于一个
*/
#include <iostream>
using namespace std;

struct Binode{
    char data;
    Binode *lchild;
    Binode *rchild;
};

struct stack{   //利用栈来保存祖先结点
    Binode *p;
    int flag;      //flag=0,表示左子女被访问；=1表示右子女被访问
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

//利用非递归的后序遍历算法
void printX(BiTree T,char x){
    stack st[10];
    int top=-1;     //指向栈顶
    while(T || top>-1){
        //依次保存左子女(不为x)
        while(T && T->data!=x){
            st[++top].p=T;
            st[top].flag=0;     //左子女被访问
            T=T->lchild;
        }
        //如果找到，输出所有结点
        if(T && T->data==x){
            for(int i=0; i<=top; ++i) cout<<st[i].p->data<<' ';
            break;
        }
        //没找到，将右节点被访问过的结点出栈
        while(top>-1 && st[top].flag==1) top--;
        //左子树找完，从右子树开始找
        if(top>-1){
            st[top].flag=1;
            T=st[top].p->rchild;
        }
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
    
    printX(T,'G'); cout<<endl;
    printX(T,'E'); cout<<endl;;
    
}
