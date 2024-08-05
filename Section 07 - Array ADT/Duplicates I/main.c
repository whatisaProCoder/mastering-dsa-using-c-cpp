#include <stdio.h>
#include <stdlib.h>

///Finding duplicates in a sorted array.

int main()
{
    int arr[10]={3,6,8,8,10,12,15,15,15,20};
    int i,j;
    for(i=0;i<10;i++)
    {
        if(arr[i]==arr[i+1])
        {
            j=i+1;
            while(arr[j]==arr[i]) j++;
            printf("Duplicate element [%d], %d times.\n",arr[i],j-i);
            i=j-1;
        }
    }
    return 0;
}
