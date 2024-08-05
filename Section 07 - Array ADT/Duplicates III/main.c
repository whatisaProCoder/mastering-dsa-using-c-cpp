#include <stdio.h>
#include <stdlib.h>

///Finding duplicates in an unsorted array.

int main()
{
    int i,j,count,sz=10;
    int a[]= {8,3,6,4,6,5,6,8,2,7};

    for(i=0; i<sz-1; i++)
    {
        count=1;
        if(a[i]!=-1)
        {
            for(j=i+1; j<sz; j++)
            {
                if(a[i]==a[j])
                {
                    count++;
                    a[j]=-1;
                }
            }
            if(count>1)
                printf("Duplicate [%d], %d times\n",a[i],count);
        }
    }

    return 0;
}
