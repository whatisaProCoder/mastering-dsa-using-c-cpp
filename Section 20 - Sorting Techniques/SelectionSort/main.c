#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void SelectionSort(int A[],int n)
{
    int i,j,k;

    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
                k=j;
        }
        swap(&A[i],&A[k]);
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
    int A[]={11,13,7,2,6,9,4,5,10,3}, n=10;

    SelectionSort(A,n);
    DisplayArray(A,n);

    return 0;
}
