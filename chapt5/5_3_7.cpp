/*
二叉树按二叉链表形式存储
写一个判别给定二叉树是否是完全二叉树的算法
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

//利用层序遍历算法判断，如果一层中：空结点后还有结点，即不是完全二叉树
bool isComplete(BiTree T){
    queue<Binode*>Q;
    if(T==NULL) return true;
    Q.push(T);
    while(!Q.empty()){
        Binode *p=Q.front();
        Q.pop();
        if(p){  //p非空，将其左右结点入队
            Q.push(p->lchild);
            Q.push(p->rchild);
        }
        else{   //p为空，检测后面有无结点
            while(!Q.empty()){
                p=Q.front(); Q.pop();
                if(p) return false;
            }
        }
    }
    return true;
}

int main() {
      /*创建的二叉树为
         A
       B   C
      D E F G
             H
      ABD##E##CF##G#H##
      以及
         A
       B   C
      D E F G
      ABD##E##CF##G##
    */
    BiTree T1,T2;

    cout<<"Create T1:\n";
    preCreate(T1);
    getchar();

    cout<<"Create T2:\n";
    preCreate(T2);

    preOrder(T1); cout<<endl;
    preOrder(T2); cout<<endl;

    if(isComplete(T1)) cout<<"T1 is completed.\n";
    else cout<<"T1 is not completed.\n";
    if(isComplete(T2)) cout<<"T2 is completed.\n";
    else cout<<"T2 is not completed.\n";

    return 0;
}
