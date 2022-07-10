/*
后序遍历二叉树的非递归算法
*/
#include <iostream>
#include<stack>
using namespace std;

struct Binode{
    char data;
    Binode *lchild;
    Binode *rchild;
    int flag=0;     //标志域，判断右孩子是否被访问过
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

void preOrder(BiTree T){
    if(T!=NULL){
        cout<<T->data<<' ';
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

//递归实现后序遍历
void postOrder(BiTree T){
    if(T){
        postOrder(T->lchild);
        postOrder(T->rchild);
        cout<<T->data<<' ';
    }
}

//非递归实现后序遍历
void postOrder2(BiTree T){
    stack<Binode*>st;
    Binode *p=T;
    while(p || !st.empty()){
        if(p){          //一直向左
            st.push(p);
            p=p->lchild;
        }
        else{
            p=st.top(); //指向栈顶
            if(p->rchild && p->rchild->flag==0) //右子树未被访问过
                p=p->rchild;
            else{   //右子树不存在或者右子树已经访问过
                p->flag=1;
                cout<<p->data<<' ';
                st.pop();
                p=NULL;
            }
        }
    }
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

    preOrder(T);
    cout<<endl;
    postOrder(T);
    cout<<endl;
    postOrder2(T);
}
