#include <stdio.h>
#include <stdlib.h>

int findMax(int A[],int n)
{
    int max=INT_MIN,i;
    for(i=0;i<n;i++)
    {
        if(max<A[i])
            max=A[i];
    }
    return max;
}

void CountSort(int A[],int n)
{
    int max,i,j;
    int *C;

    max=findMax(A,n);
    C=(int *)malloc((max+1)*sizeof(int));

    for(i=0;i<max+1;i++)
        C[i]=0;

    for(i=0;i<n;i++)
        C[A[i]]++;

    i=0; j=0;
    while(i<max+1)
    {
        if(C[i]>0)
        {
            A[j++]=i;
            C[i]--;
        }
        else
            i++;
    }
}

void DisplayArray(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10;

    CountSort(A,n);
    DisplayArray(A,n);

    return 0;
}
