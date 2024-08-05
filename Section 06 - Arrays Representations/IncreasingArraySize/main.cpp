#include <iostream>

using namespace std;

int main()
{
    int *p,*q;
    int i;

    p=new int[5]; //(int *)malloc(5*sizeof(int)) in C
    p[0]=3;
    p[1]=5;
    p[2]=7;
    p[3]=9;
    p[4]=11;

    q=new int[10]; //(int *)malloc(10*sizeof(int)) in C

    for(i=0;i<5;i++)
        q[i]=p[i];

    delete []p; //free(p) in C
    p=q;
    q=NULL;

    for(i=0;i<5;i++)
        cout<<p[i]<<endl;

    return 0;
}
