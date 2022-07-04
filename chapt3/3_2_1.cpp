/*
一个算术表达式包含圆括号、方括号、花括号3种类型
编写一个算法判断表达式中的括号是否配对
以字符'\0'作为算术表达式的结束符
*/
#include <iostream>
#include<stack>
using namespace std;
bool isEqual(char,char);
bool isRight(stack<char>,char);

bool isRight(stack<char>st,const char *ch){
    int i=0;
    while (ch[i]!='\0')
    {
        if(ch[i]=='('||ch[i]=='['||ch[i]=='{')  //如果是左括号，压入栈
            st.push(ch[i]);
        else{
            if(!isEqual(st.top(),ch[i])) //如果不匹配，返回false
                return false;
            else{               //如果匹配，弹出
                st.pop();
            }    
        }
        i++;
    }
    return st.empty();
}

bool isEqual(char ch1, char ch2){  //判断括号是否配对
    if(ch1=='('){return ch2==')'?true:false;}
    if(ch1=='['){return ch2==']'?true:false;}
    if(ch1=='{'){return ch2=='}'?true:false;}
    return false;
}

int main() {
    stack<char>st;  //装括号
    char ch1[]={'{','[','(','[',']','[',']',')',']','}','\0'};
    char ch2[]={'{','[','(','(','[',']','[',']',')',']','}','\0'};
    if(isRight(st,ch1)) printf("Yes\n");
    else printf("No\n");
    if(isRight(st,ch2)) printf("Yes\n");
    else printf("No\n");
}
