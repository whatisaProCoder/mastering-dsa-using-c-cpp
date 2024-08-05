#include <iostream>

using namespace std;

void fun(int *A)
{
    A[0]=15;
}

int* getArray(int n)
{
    int *p;
    p=new int[n];

    for(int i=0;i<n;i++)
        p[i]=i+1;

    return p;
}

int main()
{
    int *ptr, n=7;

    ptr=getArray(n);

    for(int i=0;i<n;i++)
        cout<<ptr[i]<<endl;

    return 0;
}
