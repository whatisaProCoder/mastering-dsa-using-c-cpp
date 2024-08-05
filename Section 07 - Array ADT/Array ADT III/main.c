#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void Display(struct Array arr)
{
    int i;
    printf("Elements are :\n");
    for(i=0; i<arr.length; i++)
        printf("%d ",arr.A[i]);
    printf("\n");
}

void InsertSort(struct Array *arr,int x) //inserts x in ascending order
{
    int i=arr->length-1;
    if(arr->length==arr->size)
        return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

void REarrangeSign(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j)
            swap(&arr->A[i],&arr->A[j]);
    }
}

int main()
{
    struct Array arr= {{2,3,4,10,15},10,5};

    printf("Value of isSorted() : %d\n",isSorted(arr));

    InsertSort(&arr,20);
    printf("After InsertSort --->\n");
    Display(arr);

    InsertSort(&arr,12);
    printf("After InsertSort --->\n");
    Display(arr);

    InsertSort(&arr,5);
    printf("After InsertSort --->\n");
    Display(arr);

    InsertSort(&arr,1);
    printf("After InsertSort --->\n");
    Display(arr);

    printf("-----------------NEW ARRAY--------------------\n");
    struct Array arr2= {{2,-3,25,10,-15,7},10,6};
    Display(arr2);

    REarrangeSign(&arr2);
    printf("After REarrangeSign --->\n");
    Display(arr2);

    return 0;
}
