#include <stdio.h>
#include <stdlib.h>

///Finding Duplicates in a String

void method1() //comparing with other letters
{
    char A[]="ADAMAS UNIVERSITY";
    int i,j,count;

    for(i=0;A[i]!='\0';i++)
    {
        count=1;
        if(A[i]!='0'&&A[i]!=' ')
        {
            for(j=i+1;A[j]!='\0';j++)
            {
                if(A[i]==A[j])
                {
                    count++;
                    A[j]='0';
                }
            }
        }
        if(count>1)
            printf("[%c] has [%d] duplicates.\n",A[i],count);
    }
}

void method2() //using hashtable **(for lowercase alphabets only)
{
    char A[]="data structures";
    int H[26]={0}; //26 alphabets
    int i,j;

    for(i=0;A[i]!='\0';i++)
        H[A[i]-97]++;

    for(i=0;i<26;i++)
        if(H[i]>1)
        printf("[%c] has [%d] duplicates.\n",i+97,H[i]);
}

void method3() //using bitwise operations **(for lowercase alphabets only)
{
    char A[]="tstructures";
    int i,H=0,x; //assuming it takes 4 bytes;

    for(i=0;A[i]!='\0';i++)
    {
        x=1;
        x=x<<(A[i]-97);
        if((x&H)>0) //masking: checking if same bits-ON or not. If ON, then returns >0 value.
            printf("Duplicate found : [%c]\n",A[i]);
        else
            H=x|H; //merging: OR-ing
    }
}

int main()
{
    //method1();
    //method2();
    method3();
    return 0;
}
