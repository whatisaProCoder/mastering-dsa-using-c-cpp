#include <iostream>

using namespace std;

class Array
{
private:
    int *A;
    int sz; //bolded for no reason
    int length;
    void Swap(int *x,int *y);
public:
    Array()
    {
        sz=10;
        length=0;
        A=new int[sz];
    }
    Array(int sz)
    {
        this->sz=sz;
        length=0;
        A=new int[sz];
    }
    ~Array()
    {
        delete []A;
    }
    void Display();
    void Append(int x);
    void Insert(int index,int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index,int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    int LeftShiftRotate();
    int RightShiftRotate();
    void REarrangeSign();
    Array* Merge(Array arr2);
};

void Array::Display()
{
    int i;
    printf("Elements are :\n");
    for(i=0; i<length; i++)
        printf("%d ",A[i]);
}

void Array::Append(int x)
{
    if(length<sz) //check for free space
        A[length++]=x;
}

void Array::Insert(int index,int x)
{
    int i;
    if(index>=0 && index<=length)
    {
        for(i=length; i>index; i--)
            A[i]=A[i-1];
        A[index]=x;
        length++;
    }
}

int Array::Delete(int index)
{
    int x=0;
    int i;
    if(index>=0 && index<length)
    {
        x=A[index];
        for(i=index; i<length-1; i++)
            A[i]=A[i+1];
        length--;
        return x;
    }
    return -1; //nothing to delete
}

void Array::Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int Array::LinearSearch(int key)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(key==A[i])
        {
            //Swap(&A[i],&A[i-1]); //Transposition
            Swap(&A[i],&A[0]);     //Move to Front
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key)
{
    int l,mid,h;
    l=0;
    h=length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==A[mid])
            return mid;
        else if(key<A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int Array::Get(int index)
{
    if(index>=0 && index<length)
        return A[index];
    return -1;
}

void Array::Set(int index,int x)
{
    if(index>=0 && index<length)
        A[index]=x;
}

int Array::Max()
{
    int max=A[0];
    int i;
    for(i=0; i<length; i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}

int Array::Min()
{
    int min=A[0];
    int i;
    for(i=0; i<length; i++)
    {
        if(A[i]<min)
            min=A[i];
    }
    return min;
}

int Array::Sum()
{
    int s=0;
    int i;
    for(i=0; i<length; i++)
        s+=A[i];
    return s;
}

float Array::Avg()
{
    return (float)Sum()/length;
}

void Array::Reverse()
{
    int i,j;
    int B[sz];
    for(i=length-1,j=0; i>=0; i--,j++)
        B[j]=A[i];
    for(i=0; i<length; i++)
        A[i]=B[i];
}

void Array::Reverse2()
{
    int i,j;
    for(i=0,j=length-1; i<j; i++,j--)
    {
        Swap(&A[i],&A[j]);
    }
}

int Array::LeftShiftRotate()
{
    int i;
    int temp=A[0];
    for(i=0; i<length; i++)
        A[i]=A[i+1];
    A[length-1]=temp; //not required for LeftShift()
}

int Array::RightShiftRotate()
{
    int i;
    int temp=A[length-1];
    for(i=length-1; i>0; i--)
        A[i]=A[i-1];
    A[0]=temp; //not required for RightShift()
}

void Array::InsertSort(int x) //inserts x in ascending order
{
    int i=length-1;
    if(length==sz)
        return;
    while(i>=0 && A[i]>x)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;
    length++;
}

int Array::isSorted()
{
    int i;
    for(i=0; i<length-1; i++)
    {
        if(A[i]>A[i+1])
            return 0;
    }
    return 1;
}

void Array::REarrangeSign()
{
    int i,j;
    i=0;
    j=length-1;
    while(i<j)
    {
        while(A[i]<0)i++;
        while(A[j]>=0)j--;
        if(i<j)
            Swap(&A[i],&A[j]);
    }
}

Array* Array::Merge(Array arr2) //arrays must sorted
{
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length);

    while(i<length && j<arr2.length)
    {
        if(A[i] < arr2.A[j])
            arr3->A[k++]=A[i++];
        else
            arr3->A[k++]=arr2.A[j++];
    }
    for(; i<length; i++)
        arr3->A[k++]=A[i];
    for(; j<arr2.length; j++)
        arr3->A[k++]=arr2.A[j];
    arr3->length=length+arr2.length;

    return arr3;
} //similarly do for Union, Intersection, Difference

int main()
{
    Array *arr1; //pointer so that sz can be determined later
    int choice;
    int index,num;
    int sz;

    printf("What should be the size of the array? ");
    scanf("%d",&sz);
    arr1=new Array(sz);

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
            arr1->Insert(index,num);
            break;
        case 2:
            printf("--------------Operation: Deletion---------------\n");
            printf("What is the index at which the element should be deleted?\n");
            scanf("%d",&index);
            arr1->Delete(index);
            break;
        case 3:
            printf("--------------Operation: Search-----------------\n");
            printf("What is the element you want to search?\n");
            scanf("%d",&num );
            index=arr1->LinearSearch(num);
            printf("The index of the %d is : %d",num,index);
            break;
        case 4:
            printf("--------------Operation: Sum--------------------\n");
            printf("Sum of elements of the array is : %d\n",arr1->Sum());
            break;
        case 5:
            printf("--------------Operation: Display----------------\n");
            arr1->Display();
            printf("\n");
            break;
        default:
            printf("Program Stopped...");
        }
    }
    while(choice<6);

    return 0;
}
