#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void BubbleSort(int A[],int n)
{
    int i,j,flag;

    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
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
    int A[]={3,7,9,10}, n=4;

    BubbleSort(A,n);
    DisplayArray(A,n);

    return 0;
}
