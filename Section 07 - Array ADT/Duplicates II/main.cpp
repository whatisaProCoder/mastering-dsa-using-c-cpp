#include <iostream>

using namespace std;

///Finding duplicates in a sorted array using HASHING.

int main()
{
    int i,sz=10;
    int a[sz]={3,6,8,8,10,12,15,15,15,20};
    int H[a[sz-1]+1]={0};
    for(i=0;i<sz;i++)
        H[a[i]]++;
    for(i=0;i<=a[sz-1];i++)
        if(H[i]>1)
        printf("Element [%d] : appears %d times\n",i,H[i]);
    return 0;
}
