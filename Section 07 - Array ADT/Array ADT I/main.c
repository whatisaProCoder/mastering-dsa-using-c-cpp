#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20]; //int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("Elements are :\n");
    for(i=0; i<arr.length; i++)
        printf("%d ",arr.A[i]);
}

void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size) //check for free space
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length; i>index; i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}

int Delete(struct Array *arr,int index)
{
    int x=0;
    int i;
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(i=index; i<arr->length-1; i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return -1; //nothing to delete
}

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int LinearSearch(struct Array *arr,int key)
{
    int i;
    for(i=0; i<arr->length; i++)
    {
        if(key==arr->A[i])
        {
            //swap(&arr->A[i],&arr->A[i-1]); //Transposition
            swap(&arr->A[i],&arr->A[0]);     //Move to Front
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr,int key)
{
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int RBinarySearch(int arr[],int l,int h,int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr[mid])
            return mid;
        else if(key<arr[mid])
            return RBinarySearch(arr,l,mid-1,key);
        else
            return RBinarySearch(arr,mid+1,h,key);;
    }
    return -1;
}

int main()
{
    struct Array arr= {{2,3,4,5,6},10,5};

    /*
    printf("Enter size of an array : ");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;

    printf("Enter number of numbers : ");
    scanf("%d",&n);

    printf("Enter all elements :\n");
    for(i-0; i<n; i++)
        scanf("%d",&arr.A[i]);
    arr.length=n;
    */

    Append(&arr,10); //appending 10 on inputted array
    Insert(&arr,2,10); //inserting 10 at index=2

    //deleting element at index=2
    printf("Deleted Element : %d\n",Delete(&arr, 2));

    Display(arr);
    /* LINEAR-SEARCH PORTION
    printf("\nIndex of Linear-Searched Element: %d\n",LinearSearch(&arr,5));
    //15 unavailable, returns -1
    printf("After Linear-Search, modified array :\n");
    Display(arr);
    */
    printf("\nBinary-Search Function Returns           : %d\n",BinarySearch(arr,5));
    printf("Recursive Binary-Search Function Returns : %d\n",RBinarySearch(arr.A,0,arr.length-1,5));

    return 0;
}
