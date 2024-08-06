#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
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
    for(i=0; i<arr.length; i++)
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
    for(i=arr->length-1,j=0; i>=0; i--,j++)
        B[j]=arr->A[i];
    for(i=0; i<arr->length; i++)
        arr->A[i]=B[i];
}

void Reverse2(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1; i<j; i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

int LeftShiftRotate(struct Array *arr)
{
    int i;
    int temp=arr->A[0];
    for(i=0; i<arr->length; i++)
        arr->A[i]=arr->A[i+1];
    arr->A[arr->length-1]=temp; //not required for LeftShift()
}

int RightShiftRotate(struct Array *arr)
{
    int i;
    int temp=arr->A[arr->length-1];
    for(i=arr->length-1; i>0; i--)
        arr->A[i]=arr->A[i-1];
    arr->A[0]=temp; //not required for RightShift()
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
    for(i=0; i<arr.length-1; i++)
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

struct Array* Merge(struct Array *arr1,struct Array *arr2) //arrays must sorted
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(; i<arr1->length; i++)
        arr3->A[k++]=arr1->A[i];
    for(; j<arr2->length; j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;

    return arr3;
}

struct Array* Union(struct Array *arr1,struct Array *arr2) //arrays must sorted
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++]; //if arr1[i]==arr2[j], copy one element
            j++; //but increment both i and j
        }
    }
    for(; i<arr1->length; i++)
        arr3->A[k++]=arr1->A[i];
    for(; j<arr2->length; j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Intersection(struct Array *arr1,struct Array *arr2) //arrays must sorted
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j]) i++;
        else if(arr2->A[j]<arr1->A[i]) j++;
        else if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++]; //if arr1[i]==arr2[j], copy one element
            j++; //but increment both i and j
        }
    }
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Difference(struct Array *arr1,struct Array *arr2) //arrays must sorted
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i]) j++;
        else
        {
            i++;
            j++; //if both equal, just increment i,j. No copying.
        }
    }
    for(; i<arr1->length; i++)
        arr3->A[k++]=arr1->A[i];
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

int main()
{
    struct Array arr1;
    int choice;
    int index,num;

    printf("What should be the size of the array? ");
    scanf("%d",&arr1.size);
    arr1.A=(int *)malloc(arr1.size*sizeof(int));

    do
    {
        printf("-------------------------------------------------------\n");
        printf("Can you choose an option from the following menu?\n");
        printf("    1. Insert\n");
        printf("    2. Delete\n");
        printf("    3. Search\n");
        printf("    4. Sum\n");
        printf("    5. Display\n");
        printf("    6. Exit\n");
        printf("Option? ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("--------------Operation: Insertion---------------\n");
            printf("What is the element & index at which it should be inserted?\n");
            scanf("%d%d",&num,&index);
            Insert(&arr1,index,num);
            break;
        case 2:
            printf("--------------Operation: Deletion---------------\n");
            printf("What is the index at which the element should be deleted?\n");
            scanf("%d",&index);
            Delete(&arr1,index);
            break;
        case 3:
            printf("--------------Operation: Search-----------------\n");
            printf("What is the element you want to search?\n");
            scanf("%d",&num );
            index=LinearSearch(&arr1,num);
            printf("The index of the %d is : %d",num,index);
            break;
        case 4:
            printf("--------------Operation: Sum--------------------\n");
            printf("Sum of elements of the array is : %d\n",Sum(arr1));
            break;
        case 5:
            printf("--------------Operation: Display----------------\n");
            Display(arr1);
            printf("\n");
            break;
        }
    }
    while(choice<6);

    return 0;
}
