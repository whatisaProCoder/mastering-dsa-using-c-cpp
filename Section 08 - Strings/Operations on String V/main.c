#include <stdio.h>
#include <stdlib.h>

///Reversing a String

void method1()
{
    char A[]="python";
    char B[7];
    int i,j;
    for(i=0;A[i]!='\0';i++){}
    i--;
    for(j=0;i>=0;i--,j++)
    {
        B[j]=A[i];
    }
    B[j]='\0';
    printf("%s\n",B);
}

void method2()
{
    char A[]="python"; //mutable string, pointerChar is immutable!
    char t;
    int i,j;

    for(j=0;A[j]!='\0';j++){}
    j--;
    for(i=0;i<j;i++,j--)
    {
        t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
    printf("%s\n",A);
}

int main()
{
    method1();
    method2();

    return 0;
}
