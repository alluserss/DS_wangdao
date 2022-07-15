/*
以孩子兄弟表示法存储的森林的叶子结点数
*/
#include <iostream>
using namespace std;
struct Binode{
    char data;
    Binode *lchild, *rchild;    //lchild表示孩子, rchild表示兄弟
};
typedef Binode *Bitree;
void preCreate(Bitree &T){
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else{
        T=new Binode;
        T->data=ch;
        T->lchild=NULL;
        T->rchild=NULL;
        preCreate(T->lchild);
        preCreate(T->rchild);
    }
}
void preOrder(Bitree T){
    if(T){
        cout<<T->data;
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

int numOfLeaf(Bitree T){
    if(T==NULL) return 0;
    if(T->lchild==NULL)     //左孩子为空，则为叶子结点 
        return 1+numOfLeaf(T->rchild);  //返回1+它的兄弟的叶子数
    else
        return numOfLeaf(T->lchild)+numOfLeaf(T->rchild);
}
int main() {
    /*创建的二叉树为
         A
       B   C
      D E F G
      ABD##E##CF##G##
    */
    Bitree T;
    preCreate(T);
    preOrder(T); cout<<endl;
    cout<<"叶子结点数为："<<numOfLeaf(T)<<endl;
    return 0;
}
