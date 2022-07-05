#include <iostream>
#include <stack>
using namespace std;

void Change(char *ch){
    stack<char>st;
    char *tmp=ch;
    while (*ch)
    {
        if((*ch)=='H')  //硬座入栈
            st.push(*ch);
        else            //软座放前面
            *(tmp++)=*ch;
        ch++;
    }
    while (!st.empty())
    {
        *(tmp++)=st.top();
        st.pop();
    }
}

void Print(char *ch){
    while (*ch){
        cout << *ch << ' ';
        ch++;
    }    
    cout << endl;
}

int main() {
    char ch[]={'H','S','S','H','S','H','H','S','H','\0'};   //H表示硬座、S表示软座
    Print(ch);
    Change(ch);
    Print(ch);
}
