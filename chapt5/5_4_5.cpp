/*
设计递归算法求树的深度
*/
#include <iostream>
using namespace std;
struct Binode{
    char data;
    Binode *child, *brother;    
};
typedef Binode *Bitree;
void preCreate(Bitree &T){
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else{
        T=new Binode;
        T->data=ch;
        T->child=NULL;
        T->brother=NULL;
        preCreate(T->child);
        preCreate(T->brother);
    }
}
void preOrder(Bitree T){
    if(T){
        cout<<T->data;
        preOrder(T->child);
        preOrder(T->brother);
    }
}

int deep(Bitree T){
    if(T==NULL) return 0;
    else{   //返回子女树高度+1与兄弟树高度的最大值
        int hc=deep(T->child);
        int hb=deep(T->brother);
        return 1+hc>hb ? 1+hc : hb;
    }
}

int main() {
    /*创建的树为
         A
      B  D  E
      C E H
        G
      它的孩子兄弟表示法的二叉树为：
         A
        B
       C D
        E F
       G H
       ABC##DEG##H##F### 
    */
    Bitree T;
    preCreate(T);
    preOrder(T); cout<<endl;
    cout<<"树的深度为: "<<deep(T)<<endl;
    return 0;
}
