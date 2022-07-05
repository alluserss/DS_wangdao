#include <iostream>
using std::cout; using std::cin; using std::endl;

double p(int n, double x){
    struct stack{
        int no;
        double val;
    }st[n];
    int top=-1;
    double fv1=1, fv2=2*x;
    for(int i=n; i>=2; i--)
        st[++top].no=i;
    while (top>=0)
    {
        st[top].val=2*x*fv2-2*(st[top].no-1)*fv1;
        //更新fv1,fv2
        fv1=fv2;
        fv2=st[top].val;
        top--;
    }
    if(n==0) return fv1;

    return fv2;
}

int main() {
    int x=2;
    for(int i=0; i<5; ++i){
        cout << p(i,x) << endl;
    }
    
    return 0;
}
