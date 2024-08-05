#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int A[],int l,int h)
{
    int pivot=A[l];
    int i=l,j=h;

    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);

        if(i<j)
            swap(&A[i],&A[j]);
    }while(i<j);

    swap(&A[l],&A[j]);
    return j;
}

void QuickSort(int A[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
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
    int A[]={11,13,7,2,6,9,4,5,10,3,INT_MAX}, n=11;

    QuickSort(A,0,n-1); //l,h=>indices
    DisplayArray(A,n);

    return 0;
}
