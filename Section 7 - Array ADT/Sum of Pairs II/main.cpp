#include <iostream>

using namespace std;

///Find a pair of elements with sum K using HASHING.

int main()
{
    int i,j,highest,sz=10,K=10;
    int a[sz]={6,3,8,10,16,7,5,2,9,14};

    for(i=0;i<sz;i++)
        if(highest<a[i])
        highest=a[i];

    int H[highest+1]={0};

    printf("Pairs whose sum is %d :\n",K);
    for(i=0;i<sz;i++)
    {
        H[a[i]]=1;
        if(H[K-a[i]]==1)
        printf("(%d,%d)\n",a[i],K-a[i]);
    }

    return 0;
}
