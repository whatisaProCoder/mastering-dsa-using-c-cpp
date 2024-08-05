#include <stdio.h>
#include <stdlib.h>

///Permutations of a String

void perm(char s[],int k) //using recursion
{
    static int A[10]={0};
    static char Res[10];
    int i;

    if(s[k]=='\0')
    {
        Res[k]='\0';
        printf("%s\n",Res);
    }
    else
    {
        for(i=0;s[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                Res[k]=s[i];
                A[i]=1;
                perm(s,k+1);
                A[i]=0;
            }
        }
    }
}

void swap(char *a, char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

void permm(char s[],int l,int h)
{
    int i;
    if(l==h)
        printf("%s\n",s);
    else
    {
        for(i=l;i<=h;i++)
        {
            swap(&s[l],&s[i]);
            permm(s,l+1,h);
            swap(&s[l],&s[i]);
        }
    }
}

int main()
{
    char s[]="ABC";
    perm(s,0);
    printf("\n");
    permm(s,0,2);

    return 0;
}
