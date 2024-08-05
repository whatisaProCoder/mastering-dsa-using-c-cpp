#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int A[],int n)
{
    int i,j,x;

    for(i=1;i<n;i++)
    {
        j=i-1;
        x=A[i];
        while(j>=0 && A[j]>x )
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
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

    InsertionSort(A,n);
    DisplayArray(A,n);

    return 0;
}
