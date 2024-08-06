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

int Get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr,int index,int x)
{
    if(index>=0 && index<arr->length)
        arr->A[index]=x;
}

int Max(struct Array arr)
{
    int max=arr.A[0];
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min=arr.A[0];
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}

int Sum(struct Array arr)
{
    int s=0;
    int i;
    for(i=0;i<arr.length;i++)
        s+=arr.A[i];
    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i,j;

    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];
}

void Reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

int LeftShiftRotate(struct Array *arr)
{
    int i;
    int temp=arr->A[0];
    for(i=0;i<arr->length;i++)
        arr->A[i]=arr->A[i+1];
    arr->A[arr->length-1]=temp; //not required for LeftShift()
}

int RightShiftRotate(struct Array *arr)
{
    int i;
    int temp=arr->A[arr->length-1];
    for(i=arr->length-1;i>0;i--)
        arr->A[i]=arr->A[i-1];
    arr->A[0]=temp; //not required for RightShift()
}

int main()
{
    struct Array arr= {{2,3,4,5,6},10,5};
    Display(arr);
    printf("Element at index 2 => %d\n",Get(arr,2));

    Set(&arr,0,25);
    Display(arr);

    printf("Maximum number => %d\n",Max(arr));
    printf("Minimum number => %d\n",Min(arr));
    printf("Summation      => %d\n",Sum(arr));
    printf("Average        => %f\n",Avg(arr));

    Display(arr);
    Reverse2(&arr); //Reverse(&arr)
    printf("After reversing the array----->\n");
    Display(arr);

    LeftShiftRotate(&arr); //Reverse(&arr)
    printf("After LeftShiftRotating the array------>\n");
    Display(arr);

    RightShiftRotate(&arr); //Reverse(&arr)
    printf("After RightShiftRotating the array----->\n");
    Display(arr);

    return 0;
}
