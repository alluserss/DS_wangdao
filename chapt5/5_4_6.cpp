/*
已知一棵树的层次序列以及每个结点的度
编写算法构造此树的孩子-兄弟链表
*/
#include <iostream>
using namespace std;
const int Max=20;
struct Binode{
    char data;
    Binode *child, *brother;    
};
typedef Binode *Bitree;
void Create(Bitree &T, char ch[], int degree[],int n){
    //用一个动态数组保存各个结点
    Bitree *pointer = new Bitree[Max];  //数组中每个元素也是Binode*指针
    //初始化，赋值
    for(int i=0;i<n;++i){
        pointer[i]=new Binode;
        pointer[i]->data=ch[i];
        pointer[i]->child=NULL;
        pointer[i]->brother=NULL;
    }

    int k=0;
    //依次读度数
    for(int i=0;i<n;++i){
        int d=degree[i];    //结点i的度数
        if(d){          //如果有孩子,后面第一个为左孩子，剩下的为左孩子的右兄弟
            k++;        //指向i的后一个结点，即第一个孩子
            pointer[i]->child=pointer[k];    //结点i的第一个孩子
            for(int j=2; j<=d; ++j){    //将i的第一个孩子后面的d-1个结点，成为它的兄弟
                k++;
                pointer[k-1]->brother=pointer[k];
            }            
        }
    }
    T=pointer[0];
    delete[]pointer;
}

void preOrder(Bitree T){
    if(T){
        cout<<T->data;
        preOrder(T->child);
        preOrder(T->brother);
    }
}

int main() {
    /*创建的树为
         A
      B  D  F
      C E H
        G
    层次遍历：ABDFCEHG，度为31200100
      它的孩子兄弟表示法的二叉树为：
         A
        B
       C D
        E F
       G H
    */
    Bitree T;
    char ch[]="ABDFCEHG";
    int n=8;
    int degree[]={3,1,2,0,0,1,0,0};
    Create(T,ch,degree,n);
    preOrder(T); cout<<endl;
    
    return 0;
}
