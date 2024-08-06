#include <stdio.h>
#include <stdlib.h>

///Finding duplicates in an unsorted array using HASHING.

int main()
{
    int i,sz=10;
    int a[]= {8,3,6,4,6,5,6,8,2,7};

    int H[8+1]={0}; //8 is max, next time do HASHING in C++ only.

    for(i=0;i<sz;i++)
        H[a[i]]++;

    for(i=0;i<8+1;i++)
        if(H[i]>1)
        printf("Element [%d], %d times\n",i,H[i]);

    return 0;
}
