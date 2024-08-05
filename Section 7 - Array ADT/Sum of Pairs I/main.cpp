#include <iostream>

using namespace std;

///Find a pair of elements with sum K.

int main()
{
    int i,j,sz=10,K=10;
    int a[sz]={6,3,8,10,16,7,5,2,9,14};

    printf("Pairs whose sum is %d :\n",K);
    for(i=0;i<sz-1;i++)
        for(j=i+1;j<sz;j++)
            if(a[i]+a[j]==K)
            printf("(%d,%d)\n",a[i],a[j]);

    return 0;
}
