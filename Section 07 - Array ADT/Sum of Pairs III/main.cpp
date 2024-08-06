#include <iostream>

using namespace std;

///Find a pair of elements with sum K if array is SORTED.

int main()
{
    int i,j,n=10,K=10;
    int a[n]={1,3,4,5,6,8,9,10,12,14};

    printf("Pairs whose sum is 10 :\n");
    i=0,j=n-1;
    while(i<j)
    {
        if(a[i]+a[j]==K)
        {
            printf("(%d,%d)\n",a[i],a[j]);
            i++; j--;
        }
        else if(a[i]+a[j]<K)
            i++;
        else
            j--;
    }

    return 0;
}
