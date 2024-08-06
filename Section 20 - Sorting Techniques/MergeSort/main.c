#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Merge(int A[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int B[h+1];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];

    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void IterativeMergeSort(int A[],int n)
{
    int p,l,h,mid,i;

    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n)
        Merge(A,0,p/2-1,n);
}

void RecursiveMergeSort(int A[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        RecursiveMergeSort(A,l,mid);
        RecursiveMergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
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

    RecursiveMergeSort(A,0,n-1);
    DisplayArray(A,n);

    return 0;
}
